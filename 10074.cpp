#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
using ll = long long;

int grid[105][105];

int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        while (cin >> n >> m) {
                if (not(n|m))
                        return 0;
                FOR(i, 0, n) {
                        FOR(j, 0, m) {
                                cin >> grid[i][j];
                                if (not grid[i][j])
                                        grid[i][j] = 1;
                                else
                                        grid[i][j] = -1<<30;

                                if (i > 0) grid[i][j] += max(grid[i-1][j], 0);
                                if (j > 0) grid[i][j] += max(grid[i][j-1], 0);
                                if (i > 0 && j > 0) grid[i][j] -= max(grid[i-1][j-1], 0);
                        }
                }

                ll max2d = -1<<30;
                ll rect = 0;
                FOR(i, 0, n) {
                        FOR(j, 0, n) {
                                FOR(k, i, n) {
                                        FOR(l, j, n) {
                                                rect = grid[k][l];
                                                if (i > 0) rect -= max(grid[i-1][l], 0);
                                                if (j > 0) rect -= max(grid[k][j-1], 0);
                                                if (i > 0 && j > 0) rect += max(grid[i-1][j-1], 0);
                                                max2d = max(max2d, rect);
                                        }
                                }
                        }
                }
                cout << max2d << "\n";
        }

        return 0;
}
