#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
double const pi = 3.141592653589793;

class triangle {
public:
        double a, b, c;
        double base, h;
        triangle() { }
        triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }

        double area() const
        {
                return base*h/2;
        }

        double inradius() const
        {
                return (2 * area()) / perimeter();
        }

        double perimeter() const
        {
                return a+b+c;
        }
};

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        double b, h;
        repi(z, 0, n) {
                if (z)
                        cout << "\n";
                cin >> b >> h;
                double side = sqrt(h*h+(b/2)*(b/2));
                triangle t(side, side, b);
                t.base = b;
                t.h = h;
                double theta = atan(2*h/b);
                double r = t.inradius();

                double total = 0.0;
                while (r>0.000001) {
                        total += 2*pi*r;
                        t.h -= t.inradius()*2;
                        t.base = 2*t.h/tan(theta);
                        t.a = sqrt((t.h*t.h) + (t.base*t.base/4));
                        t.b = t.a;
                        t.c = t.base;
                        r = t.inradius();
                }
                cout << fixed << setprecision(6) <<  setw(13) << total << "\n";
        }
        return 0;
}
