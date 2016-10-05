#include <bits/stdc++.h>

using namespace std;

double const EPS = 1e-10;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

double ans(double p, double q, double r, double s, double t, double u, double x)
{
        return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
        ios::sync_with_stdio(false);
        int p, q, r, s, t, u;
        while (cin >> p >> q >> r >> s >> t >> u) {
                double hi = 1.0;
                double lo = 0.0;
                while (hi > lo) {
                        double z = ans(p, q, r, s, t, u, hi);
                        if (equals(z, 0)) {
                                cout << fixed << setprecision(4) << z << "\n";
                                break;
                        } else {
                                double mid = (lo+hi)/2;
                                hi = (lo+hi)/2;
                        }
                }
        }
        return 0;
}
