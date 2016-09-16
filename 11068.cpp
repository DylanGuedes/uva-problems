#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

#define INF -1

struct Point {
        double x, y;
        Point(double _x, double _y) { x=_x; y=_y; }
        Point() { }
};

bool equals(double n1, double n2)
{
        return fabs(n1-n2) < EPS;
}

class Line {
public:
        double a, b, c;
        Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {
                if (equals(_a, 0) && equals(_b, 0))
                        return;
                else {
                        auto k = a ? a : b;
                        a /= k;
                        b /= k;
                        c /= k;
                }
        }
        bool operator==(const Line& r) const
        {
                return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
        }
};


pair<int, Point> intersections(const Line& r, const Line& s)
{
        auto det = r.a * s.b - r.b * s.a;

        if (equals(det, 0))
        {
                int qtd = (r == s) ? INF : 0;
                return pair<int, Point>(qtd, Point());
        } else {
                auto x = (-r.c * s.b + s.c * r.b) / det;
                auto y = (-s.c * r.a + r.c * s.a) / det;

                return pair<int, Point>(1, Point(x, y));
        }
}

int main()
{
        ios::sync_with_stdio(false);
        double a_1, b_1, c_1;
        double a_2, b_2, c_2;

        while (cin >> a_1 >> b_1 >> c_1) {
                Line l1(a_1, b_1, c_1);
                cin >> a_2 >> b_2 >> c_2;
                Line l2(a_2, b_2, c_2);

                if (a_1 == 0 && a_2 == 0 && b_1 == 0 && b_2 == 0 && c_1 == 0 && c_2 == 0)
                        return 0;

                if (equals(a_1, 0) && equals(b_1, 0)) {
                        cout << "No fixed point exists." << "\n";
                } else if (equals(a_2, 0) && equals(b_2, 0)) {
                        cout << "No fixed point exists." << "\n";
                }
                else {
                        if (equals(l1.a, l2.a) && equals(l1.b, l2.b) && not equals(l1.c, l2.c) || (l1==l2)) {
                                cout << "No fixed point exists." << "\n";
                        } else {
                                pair<int, Point> myp = intersections(l1, l2);

                                cout << "The fixed point is at " << fixed << setprecision(2) << -myp.second.x << " " << -myp.second.y << ".\n";
                        }
                }

        }
        return 0;
}
