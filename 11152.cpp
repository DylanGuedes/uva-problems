#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

double const pi = 3.141592653589793;

class Triangle {
public:
        double a, b, c;
        Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }

        double inradius() const
        {
                return (2 * area()) / perimeter();
        }

        double circumradius() const
        {
                return (a * b * c)/(4 * area());
        }

        double area() const
        {
                auto s = perimeter()/2.0;

                return sqrt(s*(s-a)*(s-b)*(s-c));
        }

        double perimeter() const
        {
                return a+b+c;
        }
};

int main()
{
        ios::sync_with_stdio(false);

        double a, b, c;

        while (cin >> a >> b >> c) {
                Triangle t(a, b, c);
                double a_outter = pi*t.circumradius()*t.circumradius();
                double a_inner = pi*t.inradius()*t.inradius();
                double tri = t.area();
                cout << fixed << setprecision(4) <<a_outter-tri << " " << tri - a_inner << " " << a_inner << "\n";
        }
        return 0;
}
