#include <iostream>
#include <vector>

using namespace std;

using ii = pair<int, int>;
vector<ii> graph[1050];
int dist[1050];

void bellmanford(int n, int s)
{
    for (int i=0; i < n+1; ++i) {
        dist[i] = 0xffffff;
    }

    dist[s] = 0;

    for (int i=0; i < n-1; ++i) {
        for (int j=0; j < n; ++j) {
            for (auto it : graph[j]) {
                if (it.first >= 0) {
                    if (dist[it.first] > dist[j] + it.second) {
                        dist[it.first] = dist[j] + it.second;
                    }
                }
            }
        }
    }
}

int main()
{
    int c;
    cin >> c;

    for (int z=0; z < c; ++z) {
        int n, m, origin, destiny, weight;
        cin >> n >> m;

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
        }

        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny >> weight;
            graph[origin].push_back(ii(destiny, weight));
        }

        bellmanford(n, 0);

        bool cycle = false;
        for (int i=0; i < n; ++i) {
            for (auto it : graph[i]) {
                if (dist[it.first] > dist[i] + it.second) {
                    cycle = true;
                    break;
                }
            }
        }

        if (not cycle)
            cout << "not possible" << endl;
        else
            cout << "possible" << endl;
    }


    return 0;
}
