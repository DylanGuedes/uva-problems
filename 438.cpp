#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)
using ii = pair<int, int>;
using ll = long long;
using dd = pair<double, double>;
double const pi = 3.141592653589793;

const double EPS = 1e-10;

class point {
public:
        double x, y;
        point() {}
        point(double _x, double _y): x(_x),y(_y) { }
};

double D(const point& p, const point& Q, const point& R)
{
        return (p.x * Q.y + p.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * p.x + Q.x * p.y);
}

class triangle {
public:
        point A, B, C;
        double a, b, c;
        triangle(const point& p, const point& q, const point& r) : A(p), B(q), C(r)
        {
                auto v1 = p.x-q.x;
                auto v2 = p.y-q.y;
                a = sqrt(v1*v1+v2*v2);

                v1 = p.x-r.x;
                v2 = p.y-r.y;
                b = sqrt(v1*v1+v2*v2);

                v1 = r.x-q.x;
                v2 = r.y-q.y;
                c = sqrt(v1*v1+v2*v2);
        }

        double perimeter() const
        {
                return a + b + c;
        }

        double area() const
        {
                double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x*B.y + C.y*A.x + B.x*A.y);

                return 0.5 * fabs(det);
        }

        double circumradius() const
        {
                return (a * b * c)/(4 * area());
        }


        // Centro do círculo circunscrito
        point circumcenter() const
        {
                auto d = 2*(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));

                auto A2 = A.x*A.x + A.y*A.y;
                auto B2 = B.x*B.x + B.y*B.y;
                auto C2 = C.x*C.x + C.y*C.y;

                auto x = (A2*(B.y - C.y) + B2*(C.y - A.y) + C2*(A.y - B.y))/d;
                auto y = (A2*(C.x - B.x) + B2*(A.x - C.x) + C2*(B.x - A.x))/d;

                return point(x, y);
        }

};

int main()
{
        ios::sync_with_stdio(false);
        point p, q, r;
        int counter = 0;
        while (cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y) {
                if (counter)
                        cout << "\n";
                triangle t(p, q, r);
                cout << fixed << setprecision(2) << 2*pi*t.circumradius() << "\n";
        }
        return 0;
}
