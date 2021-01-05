#include <stdio.h>
#include <string.h>

/*
 * Created by Aldo Manco
 */

int longestCommonSubsequence(char *s1, char *s2, int lengthS1, int lengthS2);

int recursiveLCS(char *s1, char *s2, int lengthS1, int lengthS2);

int max(char c1, char c2);

int main() {

    char string1[] = "aldo", string2[] = "mady";

    printf("\nLength of LCS is %i", longestCommonSubsequence(string1, string2, strlen(string1), strlen(string2)));
    printf("\nLength of LCS is %i", recursiveLCS(string1, string2, strlen(string1), strlen(string2)));

    return 0;
}

int longestCommonSubsequence(char *s1, char *s2, int lengthS1, int lengthS2) {

    char memo[lengthS1][lengthS2];
    char lcs[lengthS1];
    int k;

    for (int i = 0; i <= lengthS1; ++i) {
        for (int j = 0; j <= lengthS2; ++j) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
            } else if (*(s1 + i - 1) == *(s2 + j - 1)) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
                lcs[k++] = *(s1 + i - 1);
            } else if (*(s1 + i - 1) != *(s2 + j - 1)) {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
            memo[i][j] < 10 ? printf("0%i ", memo[i][j]) : printf("%i ", memo[i][j]);
        }
        puts("");
    }
    printf("%s", lcs);
    return memo[lengthS1][lengthS2];
}

int recursiveLCS(char *s1, char *s2, int i, int j) {

    int memo[i + 1][j + 1];

    if (i == 0 || j == 0) {
        memo[i][j] = 0;
    } else if (*(s1 + i) == *(s2 + j)) {
        memo[i][j] = 1 + recursiveLCS(s1, s2, i - 1, j - 1);
    } else if (*(s1 + i) != *(s2 + j)) {
        memo[i][j] = max(recursiveLCS(s1, s2, i - 1, j), recursiveLCS(s1, s2, i, j - 1));
    }
    return memo[i][j];
}

int max(char c1, char c2) {
    return c1 > c2 ? c1 : c2;
}