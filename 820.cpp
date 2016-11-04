#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
int n;
int graph[105][105];
int parent[105];
int residual[105][105];
int visited[105];

int bfs(int s, int t)
{
        memset(visited, 0, sizeof visited);
        queue<int> myq;
        myq.push(s);
        visited[s]=1;
        while (not myq.empty()) {
                int idx = myq.front();
                myq.pop();
                rep(i, 0, n) {
                        if (!visited[i] && residual[idx][i]) {
                                parent[i]=idx;
                                myq.push(i);
                                visited[i]=1;
                        }
                }
        }

        return visited[t];
}

int ford_fulkerson(int s, int t)
{
        int maxflow=0;

        rep(i, 0, n) rep(j, 0, n) residual[i][j] = graph[i][j];

        while (bfs(s, t)) {
                int residual_capacity=1<<30;

                for (int idx=t; idx!=s; idx=parent[idx]) {
                        residual_capacity = min(residual_capacity, residual[parent[idx]][idx]);
                }

                maxflow+=residual_capacity;

                for (int idx=t; idx!=s; idx=parent[idx]) {
                        residual[parent[idx]][idx]=max(0, residual[parent[idx]][idx]-residual_capacity);
                        residual[idx][parent[idx]]=residual_capacity;
                }
        }

        return maxflow;
}

int main()
{
        ios::sync_with_stdio(false);
        int s, t, c;
        int counter = 0;
        while (cin >> n) {
                if (!n)
                        return 0;
                cin >> s >> t >> c;
                int origin, destination, weight;
                memset(graph, 0, sizeof graph);
                rep(i, 0, c) {
                        cin >> origin >> destination >> weight;
                        origin-=1;
                        destination-=1;
                        graph[origin][destination]+=weight;
                        graph[destination][origin]+=weight;
                }
                s-=1;
                t-=1;

                cout << "Network " << counter+1 << "\n";
                cout << "The bandwidth is " << ford_fulkerson(s, t) << ".\n";
                cout << "\n";
                counter++;
        }
        return 0;
}
