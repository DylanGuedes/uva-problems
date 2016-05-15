#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dist[120];
vector<int> graph[120];
int weight[120];

void connect(int x, int y)
{
    graph[x].push_back(y);
}

void bellmanford(int n)
{
    for (int i=0; i < n+1; ++i)
        dist[i] = 0xffffff;

    dist[0] = 0;
    for (int i=0; i < n-1; ++i) {
        for (int j=0; j < n; ++j) {
            for (auto it : graph[j]) {
                if (dist[it] == 0xffffff) {
                    if (dist[it] > dist[j] + weight[it]) {
                        dist[it] = dist[j] + weight[it];
                    }
                } else {
                    if (dist[it] < dist[j] + weight[it]) {
                        if (100*n < dist[j] + weight[it]) {
                            cout << "dist[it]: " << dist[it] << endl;
                        } else {
                            cout << "dist[j] + w: " << dist[j] << weight[it] << endl;
                            dist[it] = dist[j] + weight[it];
                            cout << "dist[it]: " << dist[it] << endl;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m, destiny;
    int counter = 0;
    while (cin >> n) {
        if (n == -1)
            return 0;

        memset(weight, 0, sizeof weight);

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
        }

        for (int i=0; i < n; ++i) {
            cin >> weight[i];
            cin >> m;
            for (int j=0; j < m; ++j) {
                cin >> destiny;
                connect(i, destiny-1);
            }
        }

        bellmanford(n);

        bool winnable = true;
        for (int i=0; i < n; ++i) {
            if (dist[i] + 100 <= 0) {
                // printf("dist[%d] => %d, not winnable\n", i, dist[i]);
                winnable = false;
                break;
            }
        }

        for (int i=0; i < n; ++i) {
            printf("dist[%d] => %d\n", i, dist[i] );
        }

        cout << "Case: " << counter+1 << ", n: " << n << endl;
        if (not winnable) {
            cout << "hopeless" << endl;
        } else {
            cout << "winnable" << endl;
        }
        ++counter;
    }
    return 0;
}
