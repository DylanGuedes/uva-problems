#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
using ll = long long;

int grid[105][105];

int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        int t;
        cin >> t;
        while(t--) {
                cin >> n;
                FOR(i, 0, n) {
                        FOR(j, 0, n) {
                                cin >> grid[i][j];

                                if (i > 0) grid[i][j] += grid[i-1][j];
                                if (j > 0) grid[i][j] += grid[i][j-1];
                                if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
                        }
                }

                ll max2d = -1<<30;
                ll rect = 0;
                FOR(i, 0, n) {
                        FOR(j, 0, n) {
                                FOR(k, i, n) {
                                        FOR(l, j, n) {
                                                rect = grid[k][l];
                                                if (i > 0) rect -= grid[i-1][l];
                                                if (j > 0) rect -= grid[k][j-1];
                                                if (i > 0 && j > 0) rect += grid[i-1][j-1];
                                                max2d = max(max2d, rect);
                                        }
                                }
                        }
                }
                cout << max2d << "\n";
        }

        return 0;
}
