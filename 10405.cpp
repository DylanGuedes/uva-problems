#include <iostream>
#include <cstring>

using namespace std;

int dp[1009][1010];
string s1, s2;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int lcs(int idx1, int idx2)
{
    if (idx1 >= s1.size() || idx2 >= s2.size())
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (s1[idx1] == s2[idx2]) {
        return 1+lcs(idx1+1, idx2+1);
    } else {
        return max(lcs(idx1+1, idx2), lcs(idx1, idx2+1));
    }
}

int main()
{
    while (getline(cin, s1)) {
        getline(cin, s2);
        memset(dp, 0, sizeof dp);

        int s1size = s1.size()+1;
        int s2size = s2.size()+1;
        int res = 0;
        FOR(i, 1, s1size) {
            FOR(j, 1, s2size) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

                res = max(res, dp[i][j]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
