#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)
using ii = pair<int, int>;
using ll = long long;
using dd = pair<double, double>;

const double EPS = 1e-7;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

char inv(char a)
{
        if (a == '+')
                return '-';
        else
                return '+';
}

class point {
public:
        double x, y;
        point() {}
        point(double _x, double _y): x(_x),y(_y) { }
};

double D(const point& p, const point& Q, const point& R)
{
        return (p.x * Q.y + p.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * p.x + Q.x * p.y);
}

class triangle {
public:
        point A, B, C;
        double a, b, c;
        triangle(const point& p, const point& q, const point& r) : A(p), B(q), C(r)
        {
                auto v1 = p.x-q.x;
                auto v2 = p.y-q.y;
                a = sqrt(v1*v1+v2*v2);

                v1 = p.x-r.x;
                v2 = p.y-r.y;
                b = sqrt(v1*v1+v2*v2);

                v1 = r.x-q.x;
                v2 = r.y-q.y;
                c = sqrt(v1*v1+v2*v2);
        }

        double perimeter() const
        {
                return a + b + c;
        }

        double area() const
        {
                double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x*B.y + C.y*A.x + B.x*A.y);

                return 0.5 * fabs(det);
        }

        double circumradius() const
        {
                return (a * b * c)/(4 * area());
        }


        // Centro do círculo circunscrito
        point circumcenter() const
        {
                auto d = 2*(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));

                auto A2 = A.x*A.x + A.y*A.y;
                auto B2 = B.x*B.x + B.y*B.y;
                auto C2 = C.x*C.x + C.y*C.y;

                auto x = (A2*(B.y - C.y) + B2*(C.y - A.y) + C2*(A.y - B.y))/d;
                auto y = (A2*(C.x - B.x) + B2*(A.x - C.x) + C2*(B.x - A.x))/d;

                return point(x, y);
        }

};

void p_sep(double val)
{
        char sig = val > EPS ? '+' : '-';
        cout << sig << " " << fixed <<setprecision(3) << (val < EPS ? val*-1 : val);
}

int main()
{
        ios::sync_with_stdio(false);
        point p, q, r;
        int counter = 0;
        while (cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y) {
                if (counter)
                        cout << "\n";

                triangle t(p, q, r);
                point center = t.circumcenter();

                char x_sig, y_sig;


                if (equals(0, center.x)) {
                        cout << "x^2";
                } else {
                        cout << "(x ";
                        p_sep(center.x*-1);
                        cout << ")^2";
                }

                if (equals(0, center.y)) {
                        cout << " + y^2";
                } else {
                        cout << " + (y ";
                       p_sep(center.y*-1);
                      cout << ")^2";
                }

                cout << " = " << t.circumradius() << "^2\n";

                double e = (center.x*center.x);
                e += (center.y*center.y);
                e -= t.circumradius()*t.circumradius();

                char e_sig;
                if (e > EPS)
                        e_sig = '+';
                else {
                        e_sig = '-';
                        e*=-1;
                }

                double term_1 = -2*center.x;
                char sig_term_1;
                if (term_1 > EPS)
                        sig_term_1 = '+';
                else {
                        sig_term_1 = '-';
                        term_1 *= -1;
                }

                double term_2 = -2*center.y;
                char sig_term_2;
                if (term_2 > EPS)
                        sig_term_2 = '+';
                else {
                        sig_term_2 = '-';
                        term_2 *= -1;
                }

                cout << "x^2 + y^2";
                if (equals(term_1, 0)) {
                } else {
                        cout << " " <<sig_term_1 << " " << term_1 << "x";
                }

                if (equals(term_2, 0)) {
                } else {
                        cout << " " << sig_term_2 << " " << term_2 << "y";
                }

                if (e<0.000)
                        e*=-1;
                if (e==0) {
                        cout << " = 0\n";
                } else if (equals(e, 0)) {
                        cout << " " << (e_sig) << " " << e << " = 0\n";
                } else {
                        cout << " " << e_sig << " " << e << " = 0\n";
                }

                counter++;
        }
        return 0;
}
