#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j, k) for(int i=j; i<k; ++i)
#define ii pair<int, int>
#define iii pair<int, ii>

vector< ii > G[10010];
vector< ii > R[10010];
int distG[10010];
int distR[10010];

void dijkstraG(int source, int n, int destiny, int p)
{
    vector<int> distG(n+2, 0xffffff);
    distG[source] = 0;
    priority_queue< ii , vector< ii >, greater< ii > > mypqG;
    mypqG.push(make_pair(0, source));
    while (not mypqG.empty()) {
        int idx = mypqG.top().second;
        int val = mypqG.top().first;
        mypqG.pop();
        for (auto it : G[idx]) {
            if (distG[it.second] > it.first + distG[idx]) {
                distG[it.second] = it.first + distG[idx];
                mypqG.push(ii(distG[it.second], it.second));
            }
        }
    }

    vector<int> distR(n+2, 0xffffff);
    distR[destiny] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > mypqR;
    mypqR.push(make_pair(0, destiny));
    while (not mypqR.empty()) {
        int idx = mypqR.top().second;
        int val = mypqR.top().first;
        mypqR.pop();
        for (auto it : R[idx]) {
            if (distR[it.second] > it.first + distR[idx]) {
                distR[it.second] = it.first + distR[idx];
                mypqR.push(ii(distR[it.second], it.second));
            }
        }
    }

    int A = -1;
    FOR(i, 1, n+1) {
        for (auto it : G[i]) {
            int C = it.first + distG[i] + distR[it.second];
            if (C <= p)
                A = max(A, it.first);
        }
    }

    printf("%d\n", A);

}

int main()
{
    int T, n, m, s, t, p, u, v, c;
    cin >> T;
    while(T--) {
        cin >> n >> m >> s >> t >> p;

        FOR(i,0,n+2) {
            G[i].clear();
            R[i].clear();
        }

        FOR(i,0,m) {
            cin >> u >> v >> c;
            G[u].push_back(ii(c, v));
            R[v].push_back(ii(c, u));
        }

        dijkstraG(s, n, t, p);

    }
    return 0;
}
