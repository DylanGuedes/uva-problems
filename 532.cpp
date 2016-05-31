#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FOR(i, j, k) for(int i=j;i<k;++i)
#define ii pair<int, int>
#define iii pair< ii, int>

int l, r, c;

char grid[31][31][31];

void bfs(int sk, int sj, int si, int ek, int ej, int ei)
{
    queue<pair<int, iii > > myq;
    myq.push(make_pair(0, iii(ii(sk, sj), si)));
    grid[si][sj][sk] = '#';
    iii dest;
    dest.first.first = ek;
    dest.first.second = ej;
    dest.second = ei;

    while (not myq.empty()) {
        int idx_i = myq.front().second.second;
        int idx_j = myq.front().second.first.second;
        int idx_k = myq.front().second.first.first;
        int val = myq.front().first;
        // printf("[%d][%d][%d] => %d\n", idx_i, idx_j, idx_k, val);
        myq.pop();

        if (myq.front().second == dest) {
            printf("Escaped in %d minute(s).\n", val);
            return;
        }

        grid[idx_i][idx_j][idx_k] = '#';
        vector <iii > myv { iii(ii(idx_k, idx_j), idx_i+1),  iii(ii(idx_k, idx_j), idx_i-1), iii(ii(idx_k+1, idx_j), idx_i),  iii(ii(idx_k-1, idx_j), idx_i), iii(ii(idx_k, idx_j+1), idx_i), iii(ii(idx_k, idx_j-1), idx_i)  }; 
        for (auto it : myv) {
            if (it.first.first >= 0 && it.first.second >= 0 && it.second >= 0 && it.first.first < c && it.first.second < r && it.second < l) {
                if (grid[it.second][it.first.second][it.first.first] != '#') {
                    grid[it.second][it.first.second][it.first.first] = '#';
                    myq.push(pair <int, iii >(val+1, it));
                }
            }
        }
    }
    printf("Trapped!\n");
}

int main()
{
    int start_k, start_j, start_i, end_i, end_j, end_k; 
    while (cin >> l >> r >> c) {
        if (not (l | r | c)) 
            return 0;

        FOR(i,0,l) {
            FOR(j,0,r) {
                FOR(k,0,c) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') {
                        start_k = k;
                        start_j = j; 
                        start_i = i;
                        grid[i][j][k] = '#';
                    } else if (grid[i][j][k] == 'E') {
                        end_k = k;
                        end_j = j; 
                        end_i = i;
                    }
                }
            }
        }

        bfs(start_k, start_j, start_i, end_k, end_j, end_i);
    }
    return 0;
}
