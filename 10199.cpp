#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <set>

using namespace std;

map<string, int> inv_dict;
map<int, string> dict;
int visited[110];
int times[110];
int lowtime[110];
vector<int> graph[110];
int father[110];

set<string> cameras;

void tarjan(int idx, int num)
{
    times[idx] = num;
    lowtime[idx] = num;
    visited[idx] = 1;
    int children = 0;

    for (auto it : graph[idx]) {
        if (father[idx] == it)
            continue;
        if (visited[it] == 0) {
            children++;
            father[it] = idx;
            tarjan(it, num+1);

            lowtime[idx] = min(lowtime[idx], lowtime[it]);
            if (lowtime[it] >= times[idx] && father[idx] != idx)
                cameras.insert(dict[idx]);
            if (father[idx] == idx && children > 1)
                cameras.insert(dict[idx]);
        } else {
            lowtime[idx] = min(lowtime[idx], times[it]);
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
    int n, m;
    string tmp_buf;
    int counter = 1;
    int origin, destiny;

    while (cin >> n) {
        cameras.clear();

        if (n == 0) return 0;

        if (counter != 1)
            cout << endl;

        dict.clear(); inv_dict.clear();

        for (int i=0; i < n; ++i) {
            graph[i].clear();
            father[i] = 0;
        }

        father[0] = 0;
        for (int i=0; i < n; ++i) {
            cin >> tmp_buf;
            dict.insert(pair<int, string>(i, tmp_buf));
            inv_dict.insert(pair<string, int>(tmp_buf, i));
            father[i] = i;
        }
        cin >> m;

        for (int i=0; i < m; ++i) {
            cin >> tmp_buf;
            origin = inv_dict[tmp_buf];
            cin >> tmp_buf;
            destiny = inv_dict[tmp_buf];
            connect(origin, destiny);
        }

        memset(visited, 0, sizeof visited);
        for (int i=0; i < n; ++i) {
            if (visited[i] == 0)
                tarjan(i, 0);
        }

        cout << "City map #"<<counter<<": "<< cameras.size() << " camera(s) found" << endl;
        for (auto it=cameras.begin(); it != cameras.end(); ++it) {
            cout << *it << endl;
        }
        ++counter;

    }

    return 0;
}
