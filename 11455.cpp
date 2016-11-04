#include <bits/stdc++.h>

using namespace std;
map<int, int> mymap;

int n;
#define rep(i, j, k)for(int i=j;i<k;++i)
void to_map(int idx)
{
        if (mymap.find(idx)==mymap.end()) {
                mymap.emplace(idx, 1);
        } else {
                mymap[idx]++;
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        int sides[4];
        while(t--) {
                mymap.clear();
                rep(i, 0, 4)
                        cin >> sides[i];

                int *highest=max_element(sides, sides+4);

                rep(i, 0, 4)
                        to_map(sides[i]);


                int total=0;
                rep(i, 0, 4) {
                        if (&sides[i]!=highest)
                                total+=sides[i];
                }

                if (mymap[sides[0]]==4) {
                        cout << "square\n";
                } else if (mymap[sides[0]]==2 && mymap[sides[1]]==2 && mymap[sides[2]]==2&&mymap[sides[3]]==2) {
                        cout << "rectangle\n";
                } else if (total>=*highest) {
                        cout << "quadrangle\n";
                } else {
                        cout << "banana\n";
                }

        }
        return 0;
}
