#include <bits/stdc++.h>

using namespace std;

int n;

class pt {
public:
        pt (double _x, double _y):x(_x), y(_y) { }
        double x, y;
};

int main()
{
        ios::sync_with_stdio(false);
        double r1, r2, r3;
        cin >> n;
        while(n--) {
                cin >> r1 >> r2 >> r3;
                if (r3 > r2)
                        swap(r3, r2);
                if (r3 > r1)
                        swap(r3, r1);
                if (r2 < r1)
                        swap(r1, r2);
                pt c2(0, 0);
                pt c1(0, r2+r1);
                pt c3(sqrt((r2+r3)*(r2+r3) -(r2*r2)),r2);
        }
        return 0;
}
