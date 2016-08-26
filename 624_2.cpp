#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[21];
int dp[21][100000];

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define ii pair<int, int>

int solve(int idx, int remaining)
{
    if (idx == m)
        return 0;
    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    int ans = solve(idx+1, remaining);
    if (remaining >= arr[idx]) {
        ans = max(ans, solve(idx+1, remaining-arr[idx])+arr[idx]);
    }

    return dp[idx][remaining] = ans;
}

int backtracking()
{
    queue<pair<ii, vector<int> > >myq;
    vector<int> vz;
    myq.push(make_pair(make_pair(0, n), vz));
    vector<int> solution;
    int tempo_faltando = 0xffffff;
    while (not myq.empty()) {
        int idx = myq.front().first.first;
        int remaining = myq.front().first.second;
        vector<int> actual_vector = myq.front().second;
        if (tempo_faltando >= remaining) {
            tempo_faltando = remaining;
            solution = actual_vector;
        }

        if (idx == m) {
            myq.pop();
            continue;
        }
        vector<int> vec(myq.front().second);
        myq.push(make_pair(make_pair(idx+1, remaining), vec));
        if (arr[idx] <= remaining) {
            vector<int> othervec(vec);
            othervec.push_back(arr[idx]);
            myq.push(make_pair(make_pair(idx+1, remaining-arr[idx]), othervec));
        }
        myq.pop();
    }
    for (auto it=solution.begin(); it != solution.end(); ++it) {
        if (it != solution.begin())
            printf(" ");
        printf("%d", *it);
    }
    printf(" sum:%d\n", n-tempo_faltando);
}

int main()
{
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &m);
        FOR(i, 0, m) {
            scanf("%d", &arr[i]);
        }

        // memset(dp, -1, sizeof dp);
        // int ans = solve(0, n);
        // FOR(i, 0, m) {
        //     FOR(j, 0, n+1) {
        //         printf("[%d][%d] = %d\t", i, j, dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("%d\n", ans);
        backtracking();
    }
    return 0;
}
