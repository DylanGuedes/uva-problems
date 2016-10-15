#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const eps = 1e-10;
double const PI =3.141592653589793;

double equals(double a1, double a2)
{
        return fabs(a1-a2)<eps;
}

class triangle {
public:
        int a, b, c;
        triangle(){}
        triangle(int _a, int _b, int _c): a(_a),b(_b),c(_c) {}
        typedef enum { RIGHT, ACUTE, OBTUSE } Angles;

        Angles classification_by_angles() const
        {
                double AB = acos((double)(c*c - a*a - b*b)/(-2*a*b));
                double AC = acos((double)(b*b - a*a - c*c)/(-2*a*c));
                double BC = acos((double)(a*a - b*b - c*c)/(-2*b*c));

                auto right = PI / 2.0;

                if (equals(AB, right) || equals(AC, right) || equals(BC, right))
                        return RIGHT;

                if (AB > right || AC > right || BC > right)
                        return OBTUSE;

                return ACUTE;
        }
};

int main()
{
        ios::sync_with_stdio(false);
        int a[3];
        while (cin >> a[0] >> a[1] >> a[2]) {
                if ((a[0]+a[1]+a[2]) == 0)
                        return 0;
                triangle t(a[0], a[1], a[2]);
                if (t.classification_by_angles() == triangle::Angles::RIGHT)
                        cout << "right\n";
                else
                        cout << "wrong\n";
        }
        return 0;
}
