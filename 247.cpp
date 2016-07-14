#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <stack>

using namespace std;

vector<int> graph[30];
map<string, int> mymap;
map<int, string> dict;
stack<int> mys;
int lowtime[30];
int times[30];
int father[30];
int visited[30];
vector<int> actual_scc;

#define FOR(i, j, k)for(int i=j; i <k; ++i)

void tarjan(int idx, int val)
{
    visited[idx] = 1;
    lowtime[idx] = val;
    times[idx] = val;
    mys.push(idx);

    for (auto it : graph[idx]) {
        if (father[idx] == it)
            continue;
        if (visited[it] == 0) {
            tarjan(it, val+1);
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        } else {
            lowtime[idx] = min(lowtime[idx], times[it]);
        }
    }

    if (lowtime[idx] == times[idx]) {
        actual_scc.clear();
        while (not mys.empty()) {
            int actual = mys.top(); mys.pop();
            actual_scc.push_back(actual);
            if (actual == idx) {
                break;
            }
        }

        for (auto it=actual_scc.begin(); it != actual_scc.end(); ++it) {
            if (it != actual_scc.begin()) printf(", ");
            printf("%s", dict[*it].c_str());
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    int pointer;
    string tmp_buf;
    int origin, destiny;
    int mycountz=0;

    while (cin >> n >> m) {
        if (not (n | m))
            return 0;
        if (mycountz!=0)
            printf("\n");

        pointer = 0;
        mymap.clear();
        dict.clear();

        for (int i=0; i < m; ++i) {
            cin >> tmp_buf;
            if (mymap.find(tmp_buf) == mymap.end()) {
                mymap.insert(make_pair(tmp_buf, pointer));
                dict.insert(pair<int, string>(pointer, tmp_buf));
                ++pointer;
                origin = mymap[tmp_buf];
            } else {
                origin = mymap[tmp_buf];
            }

            cin >> tmp_buf;
            if (mymap.find(tmp_buf) == mymap.end()) {
                mymap.insert(make_pair(tmp_buf, pointer));
                dict.insert(pair<int, string>(pointer, tmp_buf));
                ++pointer;
                destiny = mymap[tmp_buf];
            } else {
                destiny = mymap[tmp_buf];
            }

            graph[origin].push_back(destiny);
        }

        memset(visited, 0, sizeof visited);
        for (int i=0; i < 30; ++i) {
            father[i] = i;
        }

        printf("Calling circles for data set %d:\n", mycountz+1);
        FOR(i, 0, n) {
            if (visited[i] == 0) {
                tarjan(i, 0);
            }
        }
        mycountz++;
    }
    return 0;
}
