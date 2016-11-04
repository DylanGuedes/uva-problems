#include <iostream>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int n, m;
int dp[105][105];
#define x first
#define y second
using ii = pair<int, int>;
int grid[105][105];
int visited[105][105];

int dfs(int u, int v)
{
        if (u<0 || v<0 || u>=n || v>=m)
                return 0;

        visited[v][u]=1;

        vector<ii> myv {ii(u+1, v), ii(u, v+1), ii(u-1, v), ii(u, v-1) };
        ans=0;
        for (auto pos : myv) {
                if (pos.x<0||pos.y<0 || pos.x>=n || pos.y>=m)
                        continue;
                if (grid[pos.y][pos.x]>=grid[v][u])
                        continue;
                ans = max(ans, 1+dfs(pos.x, pos.y));
        }
        return ans;

}

int solve()
{
        int ans=1;
        memset(visted, -1, sizeof visited);
        rep(i, 0, n) rep(j, 0, m) {
                if (!visited[i][j]) {
                        dfs(j, i);
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        scanf("%d", &t);
        rep(z, 0, t) {
                cin >> area >> n >> m;
                rep(i, 0, n) rep(j, 0, n)
                        cin >> grid[i][j];

                cout << solve() << "\n";
        }
        return 0;
}
