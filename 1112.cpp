#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>

vector<ii> graph[110];
int dist[110];

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
            graph[i].clear();
        }

        for (int i=0; i < n+1; ++i) {
            dist[i] = 0xfffffff;
        }

        dist[e-1] = 0;
        
        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny >> weight;
            graph[origin-1].push_back(ii(destiny-1, weight));
        }
        //
        // for (int i=0; i < n; ++i) {
        //     printf("dist[%d] => %d\n", i, dist[i]);
        // }

        // memset(dist, 0, sizeof dist);
        // for (int i=0; i < n+1; ++i) {
        //     dist[i] = 0xffffffff;
        // }

        for (int i=0; i < n-1; ++i) {
            for (int j=0; j < n; ++j) {
                for (auto it : graph[j]) {
                    dist[it.first] = min(dist[it.first], dist[j] + it.second);
                }
            }
        }

        for (int i=0; i < n; ++i) {
            printf("dist[%d] => %d\n", i, dist[i]);
        }

        int ans = 0;
        for (int i=0; i < n; ++i) {
            if (dist[i] <= start || e-1 == i)
                ans++;
        }
        
        cout << ans << endl;
    }
    return 0;
}
