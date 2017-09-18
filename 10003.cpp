#include <bits/stdc++.h>

using namespace std;

#define N 55
int x[N];
#define rep(i, j, k)for(int i=j;i<k;++i)
int l, n;
int dp[1010][1010];
#define oo 0xfefefe

int S(int start, int len)
{
	if (start == n)
		return 0;

	if (len < 0)
		return oo;

	if (dp[start][len] != -1)
		return dp[start][len];

	if ((x[start]+len) == x[start+1])
		return 0;

	int q = oo;
	rep(i, start+1, n) {
		if ((x[start]+len) <= x[i])
			continue;
		q = min(q, S(start, x[i] - x[start]) + S(i, len - (x[i] - x[start])) + len);
	}

	return dp[start][len] = q;
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

		n++;
		memset(dp, -1, sizeof dp);

		cout << "The minimum cutting is " << S(0, l) << ".\n";
	}
	return 0;
}
