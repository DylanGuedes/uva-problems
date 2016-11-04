#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const pi = acos(-1.0);
double const eps = 1e-10;

double x, y;

class pt {
public:
        double x, y;
        pt(double _x, double _y):x(_x),y(_y) { }
        pt() { }
};

class circle {
public:
        pt C;
        circle(pt _C):C(_C) { }
        double dist(pt P)
        {
                auto v1=fabs(P.x-C.x);
                auto v2=fabs(P.y-C.y);
                return sqrt(v1*v1+v2*v2);
        }
};

int main()
{
        ios::sync_with_stdio(false);
        int n, k, a;
        while (cin >> n >> a) {
                if (not(n|a))
                        return 0;
                circle c1(pt(0, a)), c2(pt(a, 0)), c3(pt(a, a)), c4(pt(0, 0));
                pt P;
                int M=0;
                repi(i, 0, n) {
                        cin >> P.x >> P.y;
                        if (c1.dist(P)<eps+a && c2.dist(P)<eps+a && c3.dist(P)<eps+a && c4.dist(P)<eps+a) {
                                M++;
                        }
                }
                double result = (double)M*a*a/n;

                cout << fixed << setprecision(5) << result << "\n";
        }
        return 0;
}
