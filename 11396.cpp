#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool impossible;
int visited[400];
vector<int> graph[400];
int color[400];

#define ii pair<int, int>

int inv(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 2;
    else if (n == 2)
        return 1;
}

void check_bipartite(int n)
{
    queue<ii> myq;

    color[0] = 1;
    for (int i=0; i < n; ++i) {

        if (visited[i] == 0) {
            myq.push(ii(i, 1));
            while (not myq.empty()) {
                int idx = myq.front().first;
                int act_color = myq.front().second;
                color[idx] = act_color;
                visited[idx] = 1;
                myq.pop();

                for (auto it : graph[idx]) {
                    if (color[it] == 0) {
                        color[it] = inv(act_color);
                        myq.push(ii(it, color[it]));
                    } else if (act_color == color[it]) {
                        impossible = true;
                        return;
                    }
                }
            }
        }
    }

}

void connect(int origin, int destiny)
{
    graph[origin].push_back(destiny);
    graph[destiny].push_back(origin);
}

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) return 0;

        for (int i=0; i < n; ++i) {
            graph[i].clear();
        }

        int origin, destiny;

        while (cin >> origin >> destiny) {
            if (not (origin | destiny)) {
                break;
            }

            connect(origin-1, destiny-1);
        }
        memset(color, 0, sizeof color);
        memset(visited, 0, sizeof visited);
        impossible = false;
        check_bipartite(n);


        if (impossible)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
