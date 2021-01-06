#include <stdio.h>
#include <string.h>

#define LENGTH 10

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} boolean;

typedef enum {
    white, grey, black
} Color;

typedef struct {
    int value;
    char *key;
} HashInt;

int main() {

    HashInt hashtable[LENGTH];

    for (int i = 0; i < LENGTH; ++i) {
        hashtable[i].value = -1;
        hashtable[i].key = NULL;
    }

    put(hashtable, 3, "efefer");
    put(hashtable, 6, "tegr");
    put(hashtable, 9, "ter");
    put(hashtable, 2, "teree");
    put(hashtable, 4, "tee");

    printf("\n - %i -\n", pop(hashtable, "teree"));

    put(hashtable, 98, "teep");

    printHashtable(hashtable);

    return 0;
}

int hashCode(char *key) {
    return (int) strlen(key) % LENGTH;
}

int findKey(HashInt *hashtable, char *key) {

    int hashKey = hashCode(key);

    if (hashtable[hashKey].value != -1 && hashtable[hashKey].key == key) {
        return hashKey;
    }

    int initialIndex = hashKey;

    if (hashtable[hashKey].value != -1 && hashKey == LENGTH - 1) {
        hashKey = 0;
    } else {
        hashKey++;
    }

    while (hashtable[hashKey].value != -1
           && hashKey != initialIndex
           && key != hashtable[hashKey].key) {
        hashKey = (hashKey + 1) % LENGTH;
    }

    if (hashtable[hashKey].value != -1 && hashtable[hashKey].key == key) {
        return hashKey;
    } else {
        printf("Can't find this number\n");
        return -1;
    }
}

void put(HashInt *hashtable, int value, char *key) {

    int hashKey = hashCode(key);
    int initialIndex = hashKey;

    if (hashtable[hashKey].value!=-1
        && hashKey == LENGTH - 1) {

        hashKey = 0;

    } else if (hashtable[hashKey].value!=-1
               && hashKey != LENGTH - 1) {

        hashKey++;
    }

    while (hashtable[hashKey].value!=-1
           && hashKey != initialIndex) {

        hashKey = (hashKey + 1) % LENGTH;
    }

    if (hashtable[hashKey].value!=-1) {
        printf("Cannot be added, hashtable is full\n");
        return;
    }

    HashInt hashInt;
    hashInt.value = value;
    hashInt.key = key;
    hashtable[hashKey] = hashInt;
}

int pop(HashInt *hashtable, char *key) {

    int hashKey = findKey(hashtable, key);

    if (hashKey == -1) {
        printf("Nothing to delete");
        return -1;
    }

    int deletedValue = hashtable[hashKey].value;
    hashtable[hashKey].value = -1;
    hashtable[hashKey].key = NULL;

    HashInt oldHashtable[LENGTH];
    memcpy(oldHashtable, hashtable, LENGTH);

    HashInt newHashtable[LENGTH];

    for (int i = 0; i < LENGTH; ++i) {
        newHashtable[i].value = -1;
        newHashtable[i].key = NULL;
    }

    for (int i = 0; i < LENGTH; ++i) {

        if (oldHashtable[i].value != -1) {
            put(newHashtable, oldHashtable[i].value, oldHashtable[i].key);
        }
    }
    memcpy(hashtable, newHashtable, LENGTH);

    return deletedValue;
}

int get(HashInt *hashtable, char *key) {

    int hashKey = findKey(hashtable, key);

    if (hashKey == -1) {
        return NULL;
    }
    return hashtable[hashKey].value;
}

void printHashtable(HashInt *hashtable) {

    for (int i = 1; i < LENGTH; ++i) {

        if (hashtable[i].value!=-1) {
            printf("%i, ", hashtable[i].value);
        } else if (hashtable[i].value == -1){
            printf("Empty, ");
        }
    }
}