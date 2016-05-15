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
vector<int> solutions;

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
        }
    }

    if (lowtime[idx] == times[idx]) {
        while (not mys.empty()) {
            cout << "idx: " << dict[idx]<<", top: " << dict[mys.top()] << endl;
            int act = mys.top(); mys.pop();
            solutions.push_back(act);
            if (act == idx) {
                break;
            }
        }
    }
}

int main()
{
    int n, m;
    int pointer;
    string tmp_buf;
    int origin, destiny;

    while (cin >> n >> m) {
        if (not (n | m))
            return 0;

        pointer = 0;
        mymap.clear();
        dict.clear();

        for (int i=0; i < m; ++i) {
            cin >> tmp_buf;
            if (mymap.find(tmp_buf) == mymap.end()) {
                mymap.insert(pair<string, int>(tmp_buf, pointer));
                dict.insert(pair<int, string>(pointer, tmp_buf));
                ++pointer;
                origin = mymap[tmp_buf];
            } else {
                origin = mymap[tmp_buf];
            }

            cin >> tmp_buf;
            if (mymap.find(tmp_buf) == mymap.end()) {
                mymap.insert(pair<string, int>(tmp_buf, pointer));
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

        for (int i=0; i < n; ++i) {
            if (visited[i] == 0) {
                solutions.clear();
                tarjan(i, 0);
                for (auto it : solutions) {
                    cout << dict[it] << " ";
                }
                cout << endl;
            }
        }
        cout << endl;
        
        // cout << "ADJS: " << endl;
        // for (int i=0; i < n; ++i) {
        //     cout << "Lista de " << dict[i] << endl;
        //     for (auto it : graph[i]) {
        //         cout << dict[it] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}
