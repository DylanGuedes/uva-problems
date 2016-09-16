#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
using ll = long long;

class Point {
public:
        double x, y;
        Point() { }
};

#define EPS 1e-6


vector<Point> points;
Point s;

bool equals(double n1, double n2)
{
        if (fabs(n1-n2) < EPS)
                return true;
        else
                return false;
}

bool solve(int left, int right)
{
        if (left == right)
                return (equals(points[left].x, s.x) && equals(points[left].y, s.y));
        if (not equals(s.x, (points[left].x+points[right].x)/2)) {
                return false;
        }
        if (not equals(s.y, (points[left].y+points[right].y)/2)) {
                return false;
        }
        if (left == right-1)
                return (equals((points[left].x+points[right].x)/2, s.x) && equals((points[left].y+points[right].y)/2, s.y));
        return solve(left+1, right-1);
}

bool myfunc(Point p1, Point p2)
{
        if (equals(p1.x, p2.x))
                return p1.y > p2.y;
        else
                return p1.x < p2.x;
}

int main()
{
        ios::sync_with_stdio(false);
        int c, n;
        cin >> c;
        FOR(z, 0, c) {
                cin >> n;
                Point p;
                points.clear();
                FOR(i, 0, n) {
                        cin >> p.x >> p.y;
                        points.push_back(p);
                }
                sort(points.begin(), points.end(), myfunc);
                s.x = (points[0].x+points[n-1].x)/2.0;
                s.y = (points[0].y+points[n-1].y)/2.0;
                if (equals(s.x, 0))
                        s.x += 1e-12;
                if (equals(s.y, 0))
                        s.y += 1e-12;

                solve(0, n-1) ? cout << "yes" << "\n" : cout << "no" << "\n";
        }

        return 0;
}
