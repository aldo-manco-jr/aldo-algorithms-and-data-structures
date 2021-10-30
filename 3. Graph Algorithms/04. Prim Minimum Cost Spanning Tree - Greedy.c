#include <stdio.h>

#define INF 2147483647

/*
 * Created by Aldo Manco
 */

int main() {

    int cost[][8] =
            {{INF, INF, INF, INF, INF, INF, INF, INF},
             {INF, INF, 25,  INF, INF, INF, 5,   INF},
             {INF, 25,  INF, 12,  INF, INF, INF, 10},
             {INF, INF, 12,  INF, 8,   INF, INF, INF},
             {INF, INF, INF, 8,   INF, 16,  INF, 14},
             {INF, INF, INF, INF, 16,  INF, 20,  18},
             {INF, 5,   INF, INF, INF, 20,  INF, INF},
             {INF, INF, 10,  INF, 14,  18,  INF, INF}};

    int near[8] = {INF, INF, INF, INF, INF, INF, INF, INF};

    int path[2][7];

    int i, j, k, u, v, n = 7, min = INF;

    for (i = 1; i <= n; ++i) {
        for (j = i; j <= n; ++j) {
            if (min > cost[i][j]) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    path[0][0] = u;
    path[1][0] = v;
    near[u] = near[v] = 0;

    for (i = 1; i <= n; ++i) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v]) {
                near[i] = u;
            } else {
                near[i] = v;
            }
        }
    }

    for (i = 1; i < n - 1; ++i) {

        min = INF;

        for (j = 1; j <= n; ++j) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }

        path[0][i] = near[k];
        path[1][i] = k;
        near[k] = 0;

        for (j = 1; j <= n; ++j) {
            if (near[j]!=0 && cost[j][near[j]] > cost[j][k]) {
                near[j] = k;
            }
        }
    }

    for (i = 0; i < n - 1; i++) {
        printf("%i -> %i\n", path[0][i], path[1][i]);
    }

    return 0;
}