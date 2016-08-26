#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

map<string, int> mymap;
vector<int> graph[300];
using ii = pair<int, int>;

void bfs(int origin, int destination)
{
    queue<ii> myq;
    myq.push(make_pair(0, origin));
    vector<bitset<1> > visited(mymap.size());
    visited[origin] = 1;
    while (~myq.empty()) {
        int idx = myq.front().second;
        int val = myq.front().first;
        myq.pop();
        if (idx == destination) {
            cout << val << "\n";
            return;
        }
        for (auto it : graph[idx]) {
            if (not visited[it][0]) {
                visited[it]=1;
                myq.push(make_pair(val+1, it));
            }
        }
    }
}

int main()
{
    int n;
    string myword;
    scanf("%d", &n);
    int counter = 0;
    string origin, destination;
    FOR(z, 0, n) {
        if (z)
            cout << "\n";
        mymap.clear();
        cin >> myword;
        counter = 0;
        FOR(i, 0, 215)
            graph[i].clear();
        if (myword != "*") {
            mymap.emplace(myword, counter);
            counter++;
        }

        while (myword != "*") {
            cin >> myword;
            mymap.emplace(myword, counter);
            counter++;
        }

        int nodes = mymap.size();
        for (auto i : mymap) {
            for (auto j : mymap) {
                if (i == j)
                    continue;
                if (i.first.size() == j.first.size()) {
                    int word_length = i.first.size();
                    int diff = 0;
                    FOR(k, 0, word_length) {
                        if (i.first[k] != j.first[k]) {
                            diff+=1;
                        }
                        if (diff > 1)
                            break;
                    }
                    if (diff == 1) {
                        graph[i.second].push_back(j.second);
                        graph[j.second].push_back(i.second);
                    }
                }
            }
        }

        string mystring;
        getchar();
        while (1) {
            if (not getline(cin, mystring))
                break;
            if (mystring == "")
                break;
            istringstream iss(mystring);
            iss >> origin >> destination;
            cout << origin << " " << destination << " ";
            bfs(mymap[origin], mymap[destination]);
        }
    }
    return 0;
}
