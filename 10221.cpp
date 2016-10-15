#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

double const pi = acos(-1.0);
double const eps = 1e-10;

using ll = long long;

int main()
{
        ios::sync_with_stdio(false);
        ll s;
        double a;
        string comm;
        while (cin >> s >> a >> comm) {
                a < eps ? a = fabs(a) : a;
                a = fmod(a, 360.0);
                if (comm == "min")
                        a/=60;

                ll r = 6440;
                auto that = 2*sin(a*pi/360.0)*(r+s);
                if (r+s >= (r+s + that) || that > 2*(r+s))
                        cout << fixed << setprecision(6) << 2*that;
                else {
                        // a = fmod(a, 180.0);
                        cout << fixed << setprecision(6) << (s+r)*(a*pi/180.0)<< " ";
                }
                cout << fixed << setprecision(6) << that << "\n";

        }
        return 0;
}
