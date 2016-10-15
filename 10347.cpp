#include <bits/stdc++.h>

using namespace std;

class triangle {
public:
        int a, b, c;
        triangle(int _a, int _b, int _c) : a(_a), b(_b), c(_c) { }

        double perimeter() const
        {
                return a+b+c;
        }

        double area() const
        {
                double s = perimeter() / 2.0;

                return sqrt(s)*sqrt(s - a)*sqrt(s - b)*sqrt(s - c);
        }
};

int main()
{
        ios::sync_with_stdio(false);
        int a, b, c;
        while (cin >> a >> b >> c) {
                triangle t(a, b, c);
                cout << t.area() << "\n";
        }
        return 0;
}
