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
                double v1 = l*w*h;
                auto omega = (double)l*sin(to_rad(theta));
                auto alpha = (double)90-theta;
                cout << "alpha: " << alpha << "\n";
                cout << "tan(alpha) = " << tan(to_rad(90-alpha)) <<"\n";
                auto x1 = (double)omega*tan(to_rad(90-alpha));
                cout << "x1: " << x1 << "\n";
                auto x2 = (double)l*cos(to_rad(theta));
                cout << "x2: " << x2 << "\n";
                cout << "omega: " << omega << "\n";

                double v2 = (double)omega*w*(x1+x2)/2.0;
                cout << "v2:  " << v2 << "\n";
                cout << fixed <<setprecision(3) << fabs(fabs(v1)-fabs(v2)) << " mL\n";
        }
        return 0;
}
