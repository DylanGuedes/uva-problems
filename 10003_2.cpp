#include <bits/stdc++.h>

using namespace std;

#define N 55
int x[N];
#define rep(i, j, k)for(int i=j;i<k;++i)
int l, n;
int dp[1010][1010];
#define oo 0xfefefe

int S(int i, int j)
{
	if (i+1 == j || i == j || i>j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int q = oo;
	rep(k, i+1, j) {
		q = min(q, S(i, k) + S(k, j) + x[j] - x[i]);
	}

	return dp[i][j] = q;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> l >> n) {
		if (not l)
			return 0;
		x[0] = 0;
		x[n+1] = l;
		rep(i, 1, n+1)
			cin >> x[i];

		memset(dp, -1, sizeof dp);
		cout << "The minimum cutting is " << S(0, n+1) << ".\n";
	}
	return 0;
}
