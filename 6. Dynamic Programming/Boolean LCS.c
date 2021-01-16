#include <stdio.h>
#include <string.h>

/*
 * Created by Aldo Manco
 */

typedef enum{
    false, true
}boolean;

boolean longestCommonSubsequence(char *s1, char *s2, int lengthS1, int lengthS2, int memo[][lengthS2], int k);

int recursiveLCS(char *s1, char *s2, int lengthS1, int lengthS2, int memo[][lengthS2], int k);

int max(int c1, int c2);

int main() {

    char string1[] = "maldo", string2[] = "mady";

    int memo[strlen(string1)][strlen(string2)];
    int k = 3;
    memset(memo, -1, sizeof(memo));

    printf("\nLength of LCS is %i", recursiveLCS(string1, string2, strlen(string1), strlen(string2), memo, k));
    //printf("\nLength of LCS is %i", longestCommonSubsequence(string1, string2, strlen(string1), strlen(string2), memo, k));
    if (longestCommonSubsequence(string1, string2, strlen(string1), strlen(string2), memo, k)==true){
        printf("\nTrue");
    } else{
        printf("\nFalse");
    }

    return 0;
}

boolean longestCommonSubsequence(char *s1, char *s2, int lengthS1, int lengthS2, int memo[][lengthS2], int k) {

    for (int i = 0; i <= lengthS1; ++i) {
        for (int j = 0; j <= lengthS2; ++j) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
            } else if (*(s1 + i - 1) == *(s2 + j - 1)) {
                memo[i][j] = 1 + memo[i - 1][j - 1];
                if (memo[i][j]==k){
                    return true;
                }
            } else if (*(s1 + i - 1) != *(s2 + j - 1)) {
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }
    }
    return false;
}

int recursiveLCS(char *s1, char *s2, int i, int j, int memo[][j], int k) {

    if (i == 0 || j == 0) {
        return 0;
    }

    if (memo[i - 1][j - 1] != -1) {
        return memo[i - 1][j - 1];
    }

    if (*(s1 + i) == *(s2 + j)) {
        memo[i - 1][j - 1] = 1 + recursiveLCS(s1, s2, i - 1, j - 1, memo, k);
        return memo[i - 1][j - 1];
    } else {
        memo[i - 1][j - 1] = max(recursiveLCS(s1, s2, i - 1, j, memo, k),
                                 recursiveLCS(s1, s2, i, j - 1, memo, k));
        return memo[i - 1][j - 1];
    }
}

int max(int c1, int c2) {
    return (c1 >= c2) ? c1 : c2;
}