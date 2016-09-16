#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

const double EPS = 1e-10;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

class Point {
public:
        double x, y;
        int z;
        Point(double _x, double _y) : x(_x), y(_y) { }
        Point() { }

        double length()
        {
                return sqrt(x*x + y*y);
        }

        bool operator<(const Point &comp) const
        {
                if (equals(x, comp.x))
                        return y < comp.y;
                else
                        return x < comp.x;
        }
};

class Line {
public:
        double a;
        double b;
        double c;

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
};

vector<Point> points;

double angle(const Point& P, const Point& Q, const Point& R, const Point& S)
{
        auto ux = P.x - Q.x;
        auto uy = P.y - Q.y;

        auto vx = R.x - S.x;
        auto vy = R.y - S.y;

        auto num = ux * vx + uy * vy;
        auto den = hypot(ux, uy) * hypot(vx, vy);

        return acos(num / den);
}

double vec_module(Point p1)
{
        return sqrt(p1.x*p1.x + p1.y*p1.y);
}

double easy_angle(Point P)
{
        Point p3(1.0, 0.0);

        return angle(Point(0, 0), P, Point(0, 0), p3);
}

set<Point> myset;

bool myfunc(Point p1, Point p2)
{
        Point p3(1.0, 0.0);

        auto theta1 = angle(Point(0, 0), p1, Point(0, 0), p3);
        auto theta2 = angle(Point(0, 0), p2, Point(0, 0), p3);

        if (equals(theta1, theta2)) {
                auto dist1 = vec_module(p1);
                auto dist2 = vec_module(p2);
                return  dist1 < dist2;
        } else {
                return theta1 < theta2;
        }
}

bool myfunc2(Point p1, Point p2)
{
        if (equals(p1.x, p2.x))
                return p1.y < p2.y;
        else
                return p1.x < p2.x;
}

int main()
{
        ios::sync_with_stdio(false);
        int n;
        int counter = 0;
        while (cin >> n) {
                if (not n)
                        return 0;
                Point e;
                myset.clear();
                points.clear();
                FOR(i, 0, n) {
                        cin >> e.x >> e.y >> e.z;
                        points.push_back(e);
                }

                sort(points.begin(), points.end(), myfunc);
                double high_angle = -1;
                FOR(i, 0, n) {
                        int highest_z = points[i].z;
                        auto theta1 = easy_angle(points[i]);
                        FOR(j, i+1, n) {
                                auto theta2 = easy_angle(points[j]);
                                if (equals(theta1, theta2)) {
                                        if (not (points[j].z > highest_z)) {
                                                myset.insert(points[j]);
                                        } else {
                                                highest_z = max(highest_z, points[j].z);
                                        }
                                } else {
                                        break;
                                }
                        }
                }

                cout << "Data set " << counter+1 << ":\n";
                if (myset.empty()) {
                        cout << "All the lights are visible.\n";
                } else {
                        cout << "Some lights are not visible:\n";
                        int myv_size = myset.size();
                        int myz = 0;
                        for (auto it : myset) {
                                cout << "x = " << it.x << ", y = " << it.y;
                                if (myz == myv_size-1) {
                                        cout << "." << "\n";
                                } else {
                                        cout << ";" << "\n";
                                }
                                myz++;
                        }
                }

                counter++;
        }
        return 0;
}
