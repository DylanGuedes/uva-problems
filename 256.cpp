#include <bits/stdc++.h>

#define FOR(i, j,k)for(int i=j;i<k;++i)
using namespace std;
int n;
int last_ele;

vector<int> myv;

void acc_dig(int ele)
{
        if (myv[ele] < 9)
                myv[ele]+=1;
        else {
                myv[ele]=0;
                acc_dig( ele+1);
        }
}

void solve(int num)
{
        if (num > last_ele)
                return;

        FOR(i, 0, last_ele+1) {
                int myval = pow(10, (int)(n/2));
                int total = (i%myval);
                total += (i/myval);
                total *= total;
                if (total == i)
                        cout << total << "\n";
        }
}

int main()
{
        ios::sync_with_stdio(false);
        while (cin >> n) {
                last_ele = 0;
                FOR(i, 0, n) {
                        last_ele*=10;
                        last_ele += 9;
                }
                solve(0);
        }
        return 0;
}
