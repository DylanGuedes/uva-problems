#include <bits/stdc++.h>

using namespace std;

#define rep(i,j) for(int i=0;i<j;++i)
double const pi = 3.141592653589793;

double to_rad(double theta)
{
        return theta*pi/180;
}

int main()
{
        ios::sync_with_stdio(false);
        int l, w, h, theta;
        while (cin >> l >> w >> h >> theta) {
                auto hypo1 = hypot(l, h);
                double h1=l*sin(to_rad(theta));
                auto alpha=90.0-theta;
                auto psi=90-alpha;
                auto mynicevalue = h1/cos(to_rad(psi));
                auto hypo2 = hypot(mynicevalue, l);
                double myval = atan(h/l);
                if (hypo2>hypo1) {
                        auto z=tan(to_rad(90-theta))*h;
                        cout << fixed << setprecision(3) << (z*h/2)*w << " mL\n";
                } else {
                        auto omega=h1/cos(to_rad(psi));
                        auto x2=sin(to_rad(psi))*omega;
                        auto x1=cos(to_rad(theta))*l;

                        auto area=h1*(x1+x2)/2;
                        cout << fixed <<setprecision(3) << l*h*w-area*w << " mL\n";
                }
        }
        return 0;
}
