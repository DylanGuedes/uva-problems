#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

double const EPS = 1e-9;

class Triangle {
public:
        double a, b, c;
        Triangle(double _a, double _b, double _c) : c(_c), b(_b), a(_a) {}
        Triangle() { }

        double perimeter() const
        {
                return a+b+c;
        }

        double area() const
        {
                auto s = perimeter() / 2.0;

                return sqrt(s)*sqrt(s-a)*sqrt(s-b)*sqrt(s-c);
        }

        double inradius() const
        {
                if (perimeter()) {
                        return (2.0*area())/perimeter();
                } else {
                        return 0.0;
                }
        }
};

int main()
{
        ios::sync_with_stdio(false);
        double a, b, c;
        while (cin >> a >> b >> c) {
                Triangle t(a, b, c);
                cout << "The radius of the round table is: ";
                cout << fixed << setprecision(3) << t.inradius() << "\n";
        }
        return 0;
}
