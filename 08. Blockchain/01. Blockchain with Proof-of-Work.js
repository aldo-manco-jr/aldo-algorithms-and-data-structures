
const SHA256 = require('crypto-js/sha256');

const EC = require('elliptic').ec;
const cryptoAlgorithm = new EC('secp256k1');

class Transaction{

    constructor(fromAddress, toAddress, amount){
        this.fromAddress = fromAddress;
        this.toAddress = toAddress;
        this.amount = amount;
    }

    calculateHash(){
        return SHA256(this.fromAddress + this.toAddress + this.amount).toString;
    }

    signTransaction(signingKey){
        
        if(this.fromAddress !== signingKey.getPublic('hex')){
            throw new Error("You can't sign a transaction from another wallet!");
        }

        const hashTransaction = this.calculateHash();
        const rawSignature = signingKey.sign(hashTransaction, 'base64');
        this.signature = rawSignature.toDER('hex');
    }

    isValid(){

        if(this.fromAddress==null){
            return true;
        }

        if(!this.signature || this.signature.length===0){
            throw new Error('No signature found in this transaction.');
        }

        const publicKey = cryptoAlgorithm.keyFromPublic(this.fromAddress, 'hex');
        return publicKey.verify(this.calculateHash, this.signature);
    }
}

class Block{

    constructor(timestamp, transactions, previousHash=''){
        this.timestamp = timestamp;
        this.transactions = transactions;
        this.previousHash = previousHash;
        this.hash = this.calculateHash();
        this.nonce = 0;
    }

    calculateHash(){
        return SHA256(this.timestamp + this.previousHash + JSON.stringify(this.transactions) + this.nonce).toString();
    }

    mineBlock(hardness){
        
        while(this.hash.substring(0, hardness) !== Array(hardness+1).join("0")){
            this.nonce++;
            this.hash = this.calculateHash();
        }

        //console.log('block mined: ' + this.hash + '\nnum operation: ' + this.nonce);
    }

    hasValidTransactions(){

        for (const transaction of this.transactions) {
            
            if(!transaction.isValid){
                return false;
            }
        }

        return true;
    }
}

class Blockchain{

    constructor(){
        this.chain = [this.createGenesisBlock()];
        this.hardness = 3;
        this.pendingTransactions = [];
        this.miningReward = 100;
    }

    createGenesisBlock(){
        return new Block("26/03/2020", "Genesis Block", "0");
    }

    getLatestBlock(){
        return this.chain[this.chain.length-1];
    }

    minePendingTransactions(miningRewardAddress){

        const rewardTransaction = new Transaction(null, miningRewardAddress, this.miningReward);
        this.pendingTransactions.push(rewardTransaction);
        
        let block = new Block(Date.now(), this.pendingTransactions, this.getLatestBlock().hash);
        block.mineBlock(this.hardness);

        console.log('block successfully mined!');
        this.chain.push(block);

        this.pendingTransactions = [];
    }

    addTransaction(transaction){

        if(!transaction.fromAddress || !transaction.toAddress){
            throw new Error("Transaction must include from and to address.");
        }

        if(!transaction.isValid){
            throw new Error("Cannot add invalid transaction to blockchain");
        }

        this.pendingTransactions.push(transaction);
    }

    getBalanceOfAddress(address){

        let balance = 0;

        for (const block of this.chain) {
            
            for (const transaction of block.transactions) {

                console.log("\nFrom Address: ", transaction.fromAddress,
                            "\nTo Address: ", transaction.toAddress,
                            "\nAmount: ", transaction.amount);

                if(transaction.fromAddress === address){
                    balance-=transaction.amount;
                    console.log(3);
                }

                if(transaction.toAddress === address){
                    balance+=transaction.amount;
                    console.log(3);
                }
            }
        }
        return balance;
    }

    isChainValid(){

        for (let i = 1; i < this.chain.length; i++) {

            const currentBlock = this.chain[i];
            const previousBlock = this.chain[i-1];

            if(!currentBlock.hasValidTransactions()){
                return false;
            }
            
            if(currentBlock.hash !== currentBlock.calculateHash()){
                return false;
            }

            if(currentBlock.previousHash !== previousBlock.hash){
                return false;
            }
        }
        return true;
    }
}

module.exports.Blockchain = Blockchain;
module.exports.Transaction = Transaction;