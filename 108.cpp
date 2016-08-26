#include <iostream>

using namespace std;

int grid[105][105];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int n;
    scanf("%d", &n);
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            scanf("%d", &grid[i][j]);
            if (i > 0) grid[i][j] += grid[i-1][j];
            if (j > 0) grid[i][j] += grid[i][j-1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
        }
    }

    int ans = -1<<30;
    int actual_rect = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            FOR(k, i, n) {
                FOR(l, j, n) {
                    actual_rect = grid[k][l];
                    if (i>0) actual_rect -= grid[i-1][l];
                    if (j>0) actual_rect -= grid[k][j-1];
                    if (j>0 && i>0) actual_rect += grid[i-1][j-1];

                    ans = max(ans, actual_rect);
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
