#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

#define EPS 0.00001

struct Point {
        double x;
        double y;
};

double equals(double n1, double n2)
{
        if (fabs(n1-n2) < EPS)
                return true;
        else
                return false;
}

double D(const Point& P, const Point& Q, const Point& R)
{
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

class Segment
{
public:
        Point A, B;
        Segment(const Point& Av, const Point& Bv) : A(Av), B(Bv) {}
        Segment() { }

        double length() const
        {
                return hypot(A.x - B.x, A.y - B.y);
        }

        bool contains(const Point& P) const
        {
                if (A.x == B.x)
                        return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
                else
                        return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
        }

        bool intersect(const Segment& s) const
        {
                auto d1 = D(A, B, s.A);
                auto d2 = D(A, B, s.B);
                if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B)))
                        return true;
                auto d3 = D(s.A, s.B, A);
                auto d4 = D(s.A, s.B, B);

                if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B)))
                        return true;

                return (d1 * d2 < 0) && (d3 * d4 < 0);
        }
};

int main()
{
        int n;
        int min_x_square, max_x_square, min_x_line, max_x_line;
        double xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
        scanf("%d", &n);
        FOR(z, 0, n) {
                scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &xstart, &ystart, &xend, &yend, &xleft, &ytop, &xright, &ybottom);
                bool flag = false;
                vector<Point> points;

                if (xleft > xright)
                        swap(xleft, xright);
                if (ytop < ybottom)
                        swap(ytop, ybottom);
                points.push_back(Point{(double)xleft, (double)ytop});
                points.push_back(Point{(double)xleft, (double)ybottom});
                points.push_back(Point{(double)xright, (double)ytop});
                points.push_back(Point{(double)xright, (double)ybottom});

                Segment r(Point{(double)xstart, (double)ystart}, Point{(double)xend, (double)yend});

                Segment s[4];
                s[0].A = points[0];
                s[0].B = points[1];

                s[1].A = points[0];
                s[1].B = points[2];

                s[2].A = points[1];
                s[2].B = points[3];

                s[3].A = points[2];
                s[3].B = points[3];

                auto xmin = min(xstart, xend);
                auto xmax = max(xstart, xend);
                auto ymin = min(ystart, yend);
                auto ymax = max(ystart, yend);

                if (xmin >= xleft && xmax <= xright) {
                        if (ymin >= ybottom && ymax <= ytop) {
                                flag = true;
                        }
                }

                if (not flag) {
                        FOR(i, 0, 4) {
                                if (r.intersect(s[i]) || s[i].intersect(r))
                                        flag = true;
                        }
                }

                if (flag)
                        printf("T\n");
                else
                        printf("F\n");
        }
        return 0;
}

