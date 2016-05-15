#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>

int dist[110][110];

int main()
{
    int t;
    int n, e, start;
    int m;
    int origin, destiny, weight;

    cin >> t;
    for (int z=0; z < t; ++z) {
        if (z != 0)
            printf("\n");
        cin >> n >> e >> start;
        cin >> m;

        for (int i=0; i < n+1; ++i) {
            for (int j=0; j < n+1; ++j) {
                if (i == j)
                    dist[i][j] = 0;
                else {
                    dist[i][j] = 0xfffffff;
                }
            }
        }

        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny >> weight;
            dist[origin-1][destiny-1] = weight;
        }
        //
        // for (int i=0; i < n; ++i) {
        //     printf("dist[%d] => %d\n", i, dist[i]);
        // }

        // memset(dist, 0, sizeof dist);
        // for (int i=0; i < n+1; ++i) {
        //     dist[i] = 0xffffffff;
        // }

        for (int k=0; k < n; ++k) {
            for (int i=0; i < n; ++i) {
                for (int j=0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = 0;
        for (int i=0; i < n; ++i) {
            if (dist[i][e-1] <= start || e-1 == i)
                ans++;
        }
        
        cout << ans << endl;
    }
    return 0;
}
