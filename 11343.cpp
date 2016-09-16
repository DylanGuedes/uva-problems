#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
double const EPS = 1e-8;

using ll = long long;

class Point {
public:
        double x, y;
        Point() { }
};

double D(const Point& P, const Point& Q, const Point& R)
{
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

double equals(double n1, double n2)
{
        return fabs(n1-n2) < EPS;
}

class Segment {
public:
        Point A, B;
        Segment() { }
        Segment(const Point& _A, const Point& _B) : A(_A), B(_B) { }

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

        bool collides(const Segment& s) const
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

Segment seg[110];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        FOR(z, 0, n) {
                int m;
                cin >> m;
                FOR(i, 0, m) {
                        Point p1, p2;
                        cin >> p1.x >> p1.y >> p2.x >> p2.y;
                        seg[i].A = p1;
                        seg[i].B = p2;
                }
                ll total = 0;
                FOR(i, 0, m) {
                        bool flag = false;
                        FOR(j, 0, m) {
                                if (i == j)
                                        continue;
                                if (seg[i].collides(seg[j])) {
                                        flag = true;
                                        break;
                                }
                        }
                        if (not flag)
                                total++;
                }
                cout << total << "\n";
        }
        return 0;
}
