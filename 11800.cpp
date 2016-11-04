#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

map<int, int> frequency;

class pt {
public:
        int x, y;
        pt() {}
};

void insert_side(int idx)
{
        if (frequency.find(idx)!=frequency.end()) {
                frequency[idx]++;
        } else {
                frequency.emplace(idx, 1);
        }
}

double distance(pt A, pt B)
{
        auto v1=abs(B.x-A.x);
        auto v2=abs(B.y-A.y);
        return sqrt(v1*v1+v2*v2);
}

void map_join(double val)
{
        if (frequency.find(val)==frequency.end()) {
                frequency.emplace(val, 1);
        } else {
                frequency[val]++;
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        rep(z, 0, t) {
                frequency.clear();
                pt A, B, C, D;
                cout << "Case " << z+1 << ": ";

                cin >> A.x >> A.y;
                cin >> B.x >> B.y;
                cin >> C.x >> C.y;
                cin >> D.x >> D.y;

                double distAB=distance(A, B);
                double distAC=distance(A, C);
                double distAD=distance(A, D);

                map_join(distAB);
                map_join(distAC);
                map_join(distAD);

                // if (frequency[side[0]]==4) {
                //         cout << "Square\n";
                // } else if (frequency[side[0]]==2 && frequency[side[1]]==2 && frequency[side[2]]==2 && frequency[side[3]]==2) {
                //         cout << "Rectangle\n";
                // } else if () {
                // }
        }
        return 0;
}
