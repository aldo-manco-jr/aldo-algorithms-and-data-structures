#include <stdio.h>
#include <string.h>

/*
 * Created by Aldo Manco
 */

int max(int x, int y);

int recursiveBalancedTeam(int arrayPlayers[], int arrayStrength[], int remainingStrength, int remainingPlayers,
                             int memo[][5]);

int main() {

    int arrayPlayers[5] = {1, 2, 3, 4};
    int arrayStrength[5] = {12, 21, 33, 25};
    int memo[5][5];
    memset(memo, -1, sizeof(memo));

    int totalStrength;
    int totalPlayers;

    for (int i = 0; i < 4; ++i) {
        totalStrength += arrayStrength[i];
        totalPlayers += i + 1;
    }

    printf("\n%i\n", recursiveBalancedTeam(arrayPlayers, arrayStrength, totalStrength / 2, totalPlayers, memo));

    return 0;
}

int recursiveBalancedTeam(int arrayPlayers[], int arrayStrength[], int s, int p, int memo[][5]) {

    for (int i = 0; i <= p; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (s==0 || p==0){
                memo[p][s] =0;
            }
            if (arrayStrength[i]>s){
                memo[p][s] = memo[p-1][s];
            } else{
                memo[p][s] = max(memo[p-1][s], memo[p-1][s-arrayStrength[i]])+arrayStrength[i];
            }
        }
    }
    return memo[p][s];
}

int max(int x, int y) {
    return (x > y) ? x * 1.0 : y * 1.0;
}