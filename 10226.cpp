#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

map<string, int> mymap;

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        string mystring;
        getline(cin, mystring);
        getline(cin, mystring);
        FOR(z, 0, t) {
                mymap.clear();
                int total = 0;
                while (getline(cin, mystring)) {
                        if (mystring.empty()) {
                                break;
                        } else {
                                if (mymap.find(mystring) == mymap.end()) {
                                        mymap.emplace(mystring, 1);
                                } else {
                                        mymap[mystring]++;
                                }
                                total++;
                        }
                }
                if (z)
                        cout << "\n";

                for (auto it : mymap) {
                        double val = (double)it.second/total;
                        cout << it.first << " " << fixed << setprecision(4) << val*100 << "\n";
                }
        }
        return 0;
}
