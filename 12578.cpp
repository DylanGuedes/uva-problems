#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)

double const pi = acos(-1.0);

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while(t--) {
                double l;
                cin >> l;
                l/=10;
                double r = l*2;
                double w = l*10;
                double h = l*6;

                cout << fixed << setprecision(2) << pi*r*r << " " << w*h-(pi*r*r) << "\n";
        }
        return 0;
}
