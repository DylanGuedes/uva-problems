#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

double const pi = 3.141592653589793;

struct Point {
        double x, y;
};

class Line {
public:
        Point A, B;
        Line(Point p1, Point p2) : A(p1), B(p2) {}
        double dist()
        {
                auto mya = A.x - B.x;
                auto mb = A.y - B.y;
                return sqrt((mya*mya)+(mb*mb));
        }
};

bool myfunc(Point p1, Point p2)
{
        return p1.x > p2.x;
}

int main()
{
        int t, n;
        scanf("%d", &t);
        vector<Point> points;

        FOR(z, 0, t) {
                scanf("%d", &n);
                points.clear();
                Point e;
                FOR(i, 0, n) {
                        scanf("%lf%lf", &e.x, &e.y);
                        points.push_back(e);
                }
                sort(points.begin(), points.end(), myfunc);
                int points_size = points.size();
                vector<Line> lines;
                double highest = 0.0;
                for (int i=0; i < points_size-1; i++) {
                        Line l(points[i], points[i+1]);
                        if (l.B.y < highest)
                                continue;
                        highest = l.B.y;
                        lines.push_back(l);
                }

                int lines_size = lines.size();
                highest = 0.0;
                double total = 0.0;
                total += lines[0].dist();
                for (int i=1; i < lines_size; ++i) {
                        if (lines[i].B.y < highest)
                                continue;
                        highest = max(highest, lines[i].B.y);
                        auto x = abs(lines[i].B.x - lines[i].A.x);
                        auto y = abs(lines[i].B.y - lines[i].A.y);
                        double alpha = atan(y/x);
                        auto cut_y = lines[i].B.y - lines[i-1].B.y;
                        auto r = cut_y/sin(alpha);
                        total += fabs(r);
                }
                printf("%.2lf\n", total);
        }
        return 0;
}
