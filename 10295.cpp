#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

map<string, int> mymap;
int m, n;

int main()
{
        ios::sync_with_stdio(false);
        cin >> m >> n;
        string word;
        int val;
        FOR(i, 0, m) {
                cin >> word >> val;
                mymap.emplace(word, val);
        }

        int total = 0;
        string descr;
        while (cin >> descr) {
                if (descr == ".") {
                        cout << total << "\n";
                        total = 0;
                } else {
                        if (mymap.find(descr) != mymap.end()) {
                                total += mymap[descr];
                        }
                }
        }
        return 0;
}
