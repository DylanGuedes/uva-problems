#include <bits/stdc++.h>

using namespace std;

double const EPS = 1e-10;
#define FOR(i, j, k)for(int i=j;i<k;++i)

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

double ans(double x, double y)
{
        return x*y/(x+y);
}

int main()
{
        ios::sync_with_stdio(false);
        int k;
        while (cin >> k) {
                FOR(i, k, 2*k){
                        FOR(j, i, 2*k) {
                                if (equals(k, ans(i, j))) {
                                        cout << "1/"<<k<<" = 1/"<<j <<" + 1/" << i << "\n";
                                }
                        }
                }
        }
        return 0;
}
