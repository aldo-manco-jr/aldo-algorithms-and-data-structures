#include <stdio.h>
#include <string.h>

/*
 * Created by Aldo Manco
 */

int longestPalindromeSubsequence(char *string, int, int);

int max(char c1, char c2);

int main() {

    char string1[] = "fe101ef";

    printf("\nLength of Longest Palindrome Subsequence is %i", longestPalindromeSubsequence(string1, 0, strlen(string1)-1));

    return 0;
}

int longestPalindromeSubsequence(char *string, int i, int j) {

    int memo[j + 1][j + 1];

    if(i>j){
        memo[i][j] = 0;
    }else if(i==j){
        memo[i][j] = 1;
    }else if(*(string+i) == *(string+j)){
        memo[i][j] = 2 + longestPalindromeSubsequence(string,i+1,j-1);
    } else if(*(string+i) != *(string+j)){
        memo[i][j] = max(longestPalindromeSubsequence(string,i+1,j), longestPalindromeSubsequence(string,i,j-1));
    }
    return memo[i][j];
}

int max(char c1, char c2) {
    return c1 > c2 ? c1 : c2;
}