#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const pi = acos(-1.0);

int main()
{
        ios::sync_with_stdio(false);
        int n, k, a;
        while (cin >> n >> a) {
                if (not(n|a))
                        return 0;
                double aux;
                repi(i, 0, n)
                        cin >> aux >> aux;
                double z = (a*a)*(1-(pi/6)-(sqrt(3)/6));
                double y = -2*z + (a*a)*(1-pi/4);
                double x = (a*a)-(4*y+4*z);
                cout << a << "\n";
        }
        return 0;
}
