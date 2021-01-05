#include <stdio.h>
#include <string.h>

/*
 * Created by Aldo Manco
 */

int recursiveSCS(char *s1, char *s2, int len1, int len2);

int min(int x, int y);

int main() {
    char s1[] = "ALDO", s2[] = "MADY";
    size_t len1 = strlen(s1), len2 = strlen(s2);

    printf("The length of shortest Common supersequence is %i", recursiveSCS(s1, s2, len1, len2));

    return 0;
}

int recursiveSCS(char *s1, char *s2, int len1, int len2) {

    int memo[len1 + 1][len2 + 1];

    if (len1 == 0 || len2 == 0) {
        memo[len1][len2] = len1 + len2;
    } else if (*(s1 + len1 - 1) == *(s2 + len2 - 1)) {
        memo[len1][len2] = recursiveSCS(s1, s2, len1 - 1, len2 - 1) + 1;
    } else if (*(s1 + len1 - 1) != *(s2 + len2 - 1)) {
        memo[len1][len2] = min(recursiveSCS(s1, s2, len1 - 1, len2), recursiveSCS(s1, s2, len1, len2 - 1)) + 1;
    }
    return memo[len1][len2];
}

/*int iterativeSCS(char *s1, char *s2, int len1, int len2) {

    int memo[len1 + 1][len2 + 1];

    for (int i = 0; i < len1; ++i) {
        memo[0][i] = i;
    }

    for (int j = 0; j < len2; ++j) {
        memo[j][0] = j;
    }

    for (int i = 1; i < len1; ++i) {
        for (int j = 1; j < len2; ++j) {
            if (s1[i]==s2[j]){
                return memo[i][j]++;
            } else if(s1[])
        }
    }
}*/

int min(int x, int y) {
    return (x <= y) ? x : y;
}