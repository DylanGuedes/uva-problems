#include <iostream>
#include <cmath>

using namespace std;

#define scf(n) scanf("%d", &n)
#define FOR(i, j, k)for(int i=j;i<k;++i)
#define EPS 0.00001
#define INF -1

class Point {
public:
        double x, y;
        Point() { }
        Point(double mx, double my) : x(mx), y(my) { }
};

double D(const Point& P, const Point& Q, const Point& R)
{
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

double equals(double n1, double n2)
{
        if (fabs(n1-n2) < EPS)
                return true;
        else
                return false;
}

class Line {
public:
        double a;
        double b;
        double c;

        Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}
        Line(const Point& p, const Point& q)
        {
                a = p.y - q.y;
                b = q.x - p.x;
                c = p.x * q.y - p.y * q.x;

                auto k = a ? a : b;

                a /= k;
                b /= k;
                c /= k;
        }

        bool operator==(const Line& r) const
        {
                return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
        }

        bool parallel(const Line& r) const
        {
                return equals(a, r.a) && equals(b, r.b) && !equals(c, r.c);
        }

        bool orthogonal(const Line& r) const
        {
                return equals(a * r.a + b * r.b, 0);
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
        int n;
        scf(n);

        printf("INTERSECTING LINES OUTPUT\n");
        FOR(i, 0, n) {
                Point A, B, C, D;
                scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
                Line l1(A, B), l2(C, D);
                if (l1 == l2) {
                        printf("LINE\n");
                } else if (l1.parallel(l2)) {
                        printf("NONE\n");
                } else {
                        pair<int, Point> myp = intersections(l1, l2);
                        if (fabs(myp.second.x) < EPS)
                                myp.second.x = fabs(myp.second.x);
                        if (fabs(myp.second.y) < EPS)
                                myp.second.y = fabs(myp.second.y);
                        printf("POINT %.2lf %.2lf\n", myp.second.x, myp.second.y);
                }
        }
        printf("END OF OUTPUT\n");


        return 0;
}
