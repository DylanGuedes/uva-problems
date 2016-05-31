#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, j, k) for(int i=j; i < k; ++i)
#define MEMSET(i) memset(i, 0, sizeof i)

vector<int> graph[325];
int father[325];
int visited[325];

void print_fathers(int idx)
{
    if (father[idx] == idx)
        printf("%d", idx);
    else {
        print_fathers(father[idx]);
        printf(" %d", idx);
    }
}

void bfs(int origin, int destiny)
{
    printf("bfs\n");
    queue<int> myq;
    myq.push(origin);
    while (not myq.empty()) {
        int idx = myq.front();
        printf("idx: %d\n", idx);
        myq.pop();
        visited[idx] = 1;

        if (idx == destiny) {
            printf("achei sol\n");
            print_fathers(idx);
            printf("\n");
            return;
        }

        for (auto it : graph[idx]) {
            if (visited[it] == 0) {
                father[it] = idx;
                myq.push(it); 
            }
        }
    }

    printf("connection impossible\n");
}

int main()
{
    int n;
    string mystring;
    int m, origin, destiny;

    while (cin >> n) {
        mystring.clear();

        FOR(i, 0, n+2) {
            graph[i].clear();
        }

        FOR(i, 0, n) {
            getline(cin, mystring);
            istringstream iss(mystring);

            char char_buf;

            iss >> origin;
            iss >> char_buf;

            while (iss >> destiny) {
                iss >> char_buf;
                graph[origin].push_back(destiny);
                graph[destiny].push_back(origin);
            }

        }
        cin >> m;
        printf("m: %d\n", m);
        printf("-----\n");
        cin.clear();
        FOR(i, 0, m) {
            cin >> origin >> destiny;
            scanf("%d%d", &origin, &destiny);
            MEMSET(visited);
            FOR(i, 0, n+2) {
                father[i] = i;
            }
            bfs(origin, destiny);
        }
        printf("-----\n");

    }
    return 0;
}
