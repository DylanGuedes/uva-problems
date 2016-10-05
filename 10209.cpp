#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)
double const pi = acos(-1.0);

int main()
{
        ios::sync_with_stdio(false);
        double a;
        while (cin >> a) {
                double h = a*(sqrt(3))/2;
                double z = (a*a)*(1-pi/6-(sqrt(3))/4);
                double y = (a*a-(pi*(a*a)/4))-2*z;
                double r = a;
                double area = a*a;
                double a1 = pi*r*r/4 - 3*y -2*z;
                cout << fixed <<setprecision(3) << a1 << " " << 4*y << " " << 4*z << "\n";
        }
        return 0;
}
