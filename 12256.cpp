#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
ll dp[100];
int n;

int main()
{
        ios::sync_with_stdio(false);
        int counter=0;
        dp[0]=1;
        dp[1]=1;
        dp[2]=1;
        dp[3]=3;

        rep(i, 4, 70) {
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }

        while (cin >> n) {
                if (not(n))
                        return 0;
                cout << "Case " << counter+1 <<": ";
                cout << dp[n-1] << "\n";
                counter++;
        }
        return 0;
}
