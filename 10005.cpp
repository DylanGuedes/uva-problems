#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
double const EPS = 1e-6;

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
        double det = (r * r / d2) - 0.25;

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

                point pt1, pt2;

                rep(i, 0, n) {
                        cin >> arr[i].x >> arr[i].y;
                }

                double r;
                cin >> r;

                bool ok=false;
                rep(i, 0, n) {
                bool possible=false;
                        rep(j, i+1, n) {
                                possible=false;
                                circle circle1;
                                circle circle2;
                                pt1=arr[i];
                                pt2=arr[j];

                                possible = from2PointsAndRadius(pt1, pt2, r, circle1);
                                possible = max(possible, from2PointsAndRadius(pt2, pt1, r, circle2));

                                bool flag1 = true;
                                bool flag2 = true;

                                if (possible) {
                                        rep(k, 0, n) {
                                                if (k==i || k==j)
                                                        continue;

                                                if (distance(circle1.C, arr[k]) > (r)+EPS) {
                                                        flag1 = false;
                                                }

                                                if (distance(circle2.C, arr[k]) > (r)+EPS) {
                                                        flag2 = false;
                                                }

                                                if (not(flag1|flag2)) {
                                                        possible = false;
                                                        break;
                                                }
                                        }
                                }

                                if (possible) {
                                        ok=true;
                                        break;
                                }
                        }
                        if (possible) {
                                ok=true;
                                break;
                        }
                }

                if (ok || n==1) {
                        cout << "The polygon can be packed in the circle.\n";
                } else {
                        cout << "There is no way of packing that polygon.\n";
                }
        }
        return 0;
}
