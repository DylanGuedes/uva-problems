#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)
double const eps = 1e-10;
using ii = pair<int, int>;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < eps;
}

class point {
public:
        double x, y;
        point() { }
        point(double _x, double _y) : x(_x),y(_y) { }
};
using pp = pair<point, point>;

class segment {
public:
        point A, B;
        segment() { }
        segment(point p1, point p2) : A(p1),B(p2) { }
        bool contains(const point& P) const
        {
                if (equals(A.x, B.x))
                        return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
                else
                        return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
        }
};

double D(const point& p, const point& Q, const point& R)
{
        return (p.x * Q.y + p.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * p.x + Q.x * p.y);
}

class triangle {
public:
        point p,q,r;
        triangle(point p1, point p2, point p3) : p(p1),q(p2),r(p3) { }

        bool inside(point w)
        {
                vector<int> signs;
                vector<pair<pp, double> > ans;
                ans.eb(pp(p, q), D(p, q, w));
                ans.eb(pp(q, r), D(q, r, w));
                ans.eb(pp(r, p), D(r, p, w));
                for (auto it : ans) {
                        if (equals(it.second, 0)) {
                                segment s(it.first.first, it.first.second);
                                if (s.contains(w))
                                        return true;
                                else
                                        signs.pb(-1);

                        } else {
                                if (it.second >= eps)
                                        signs.pb(1);
                                else
                                        signs.pb(0);
                        }
                }
                bool possible = true;
                repi(i, 1, 3) {
                        if (signs[i] != signs[i-1])
                                possible = false;
                }
                return possible;
        }
};

#define all(x) x.begin(),x.end()

int main()
{
        ios::sync_with_stdio(false);
        point p, q, r;
        while (cin >> p.x >> p.y) {
                cin >> q.x >> q.y;
                cin >> r.x >> r.y;
                if (equals(p.x, 0) && equals(r.x, 0) && equals(q.x, 0) && equals(p.y, 0) && equals(r.y, 0) && equals(q.y, 0))
                        return 0;
                vector<double> help1 {p.x, q.x, r.x };
                vector<double> help2 {p.y, q.y, r.y };
                double highest_x = *max_element(all(help1));
                double highest_y = *max_element(all(help2));
                double lowest_x = *min_element(all(help1));
                double lowest_y = *min_element(all(help2));
                triangle t(p, q, r);
                int total = 0;
                repi(i, lowest_y-1, highest_y+1) repi(j, lowest_x-1, highest_x+1) {
                        if (t.inside(point(j, i)))
                                total++;
                }
                cout << total << "\n";
        }
        return 0;
}
