#include <bits/stdc++.h>

using namespace std;

int x, y;

class pt {
public:
        int x, y;
        pt(int _x, int _y):x(_x),y(_y) { }
};

int solve(pt p, int k)
{
        // cout << "solve({"<<p.x<<","<<p.y<<"},"<<k<<")\n";
        if (k<1 || p.x>2048 || p.y>2048 || p.x<0 || p.y<0)
                return 0;
        int ans=0;

        double px=p.x, py=p.y, dx=x, dy=y;
        // cout << "div:" << px+k/2.0 << "\n";
        double coef=(2*k+1)/2;
        if (px+coef>=x && px-coef<=x && py+coef>=y && py-coef<=y) {
                // cout << "solve({"<<p.x<<","<<p.y<<"},"<<k<<")\n";
                // cout << "sim..\n";
                ans+=1;
        } else {
        }

        if (k==1)
                return ans;

        vector<pt> myv {pt(p.x-coef, p.y-coef), pt(p.x-coef, p.y+coef), pt(p.x+coef, p.y-coef), pt(p.x+coef, p.y+coef) };
        for (auto it : myv) {
                ans+=solve(it, k/2);
        }

        return ans;
}

int main()
{
        ios::sync_with_stdio(false);
        int k;
        while (cin >> k >> x >> y) {
                if (not(k|x|y))
                        return 0;
                pt position(1024, 1024);
                cout << fixed << setw(3) <<solve(position, k) << "\n";
        }
        return 0;
}
