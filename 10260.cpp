#include <bits/stdc++.h>

using namespace std;
#define FOR(i, j, k)for(int i=j;i<k;++i)

map<char, int> mymap;

int main()
{
        ios::sync_with_stdio(false);
        string mys;

        mymap.clear();

        mymap.emplace('B', 1);
        mymap.emplace('F', 1);
        mymap.emplace('P', 1);
        mymap.emplace('V', 1);
        mymap.emplace('C', 2);
        mymap.emplace('G', 2);
        mymap.emplace('J', 2);
        mymap.emplace('K', 2);
        mymap.emplace('Q', 2);
        mymap.emplace('S', 2);
        mymap.emplace('X', 2);
        mymap.emplace('Z', 2);
        mymap.emplace('D', 3);
        mymap.emplace('T', 3);
        mymap.emplace('L', 4);
        mymap.emplace('M', 5);
        mymap.emplace('N', 5);
        mymap.emplace('R', 6);

        while (cin >> mys) {
                int mys_size = mys.size();
                FOR(i, 0, mys_size) {
                        if (mymap.find(mys[i]) == mymap.end())
                                continue;
                        else {
                                if (not mymap[mys[i]])
                                        continue;
                        }
                        if (i) {
                                if (mymap[mys[i]] == mymap[mys[i-1]])
                                        continue;
                                cout << mymap[mys[i]];
                        } else {
                                cout << mymap[mys[i]];
                        }
                }
                cout << "\n";
        }
        return 0;
}
