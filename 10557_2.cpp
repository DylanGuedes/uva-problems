#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dist[120];
int friends[120][120];
int weight[120];

void connect(int x, int y)
{
    friends[x][y] = 1;
}

void bellmanford(int n)
{
    for (int i=0; i < n+1; ++i)
        dist[i] = 0xffffff;

    dist[0] = 0;
    for (int i=0; i < n-1; ++i) {
        for (int j=0; j < n; ++j) {
            for (int z=0; z < n; ++z) {
                if (friends[j][z] == 1) {
                    if (dist[z] == 0xffffff) {
                        if (dist[z] > dist[j] + weight[z]) {
                            dist[z] = dist[j] + weight[z];
                        }
                    } else {
                        if (dist[z] < dist[j] + weight[z]) {
                            if (100*n < dist[j] + weight[z]) {

                            } else {
                                dist[z] = dist[j] + weight[z];
                            }

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
        memset(friends, 0, sizeof friends);
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
