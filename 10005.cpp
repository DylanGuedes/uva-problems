#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const EPS = 1e-10;

class point {
public:
        double x, y;
        point() { }
        point(double _x, double _y) : x(_x),y(_y) { }
};

class circle {
public:
        point C;
        double r;

        circle(const point& Cv = point(0, 0), double rv = 1.0) : C(Cv), r(rv) {}

};

bool
from2PointsAndRadius(const point& P, const point& Q, double r, circle& c)
{
        double d2 = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
        double det = r * r / d2 - 0.25;

        if (det < 0.0)
                return false;

        double h = sqrt(det);

        auto x = (P.x + Q.x) * 0.5 + (P.y - Q.y) * h;
        auto y = (P.y + Q.y) * 0.5 + (Q.x - P.x) * h;

        c = circle(point(x, y), r);

        return true;
}

double distance(point p1, point p2)
{
        auto v1 = p1.x - p2.x;
        auto v2 = p1.y - p2.y;
        return sqrt(v1*v1+v2*v2);
}

point arr[110];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        while (cin >> n) {
                if (!n)
                        return 0;
                point highest_y, highest_x;
                highest_y.y = -1<<30;
                highest_x.x = -1<<30;

                if (n == 2) {
                        cin >> arr[0].x >> arr[0].y;
                        cin >> arr[1].x >> arr[1].y;
                        highest_x = arr[0];
                        highest_y = arr[1];
                } else {
                        repi(i, 0, n) {
                                cin >> arr[i].x >> arr[i].y;
                                if (highest_y.y < abs(arr[i].y))
                                        highest_y = arr[i];
                                if (highest_x.x < abs(arr[i].x))
                                        highest_x = arr[i];
                        }
                }

                double r;
                cin >> r;

                circle circle1;
                circle circle2;
                bool possible = from2PointsAndRadius(highest_x, highest_y, r, circle1);
                possible = from2PointsAndRadius(highest_y, highest_x, r, circle2);

                if (possible) {
                        bool flag1 = true;
                        bool flag2 = true;
                        repi(i, 0, n) {
                                if (distance(circle1.C, arr[i]) > (r+EPS)) {
                                        flag1 = false;
                                }

                                if (distance(circle2.C, arr[i]) > (r+EPS)) {
                                        flag2 = false;
                                }

                                if (not(flag1|flag2)) {
                                        possible = false;
                                        break;
                                }
                        }
                }

                if (possible) {
                        cout << "The polygon can be packed in the circle.\n";
                } else {
                        cout << "There is no way of packing that polygon.\n";
                }
        }
        return 0;
}
