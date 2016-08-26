#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

vector<int> w;
int m;
int dp[21][410][400];

bool knapsack(int idx, int c1, int c2)
{
    if (idx == m) {
        return c1 == c2;
    }

    if (dp[idx][c1][c2] != -1)
        return dp[idx][c1][c2];

    bool p1 = knapsack(idx+1, w[idx]+c1, c2);
    bool p2 = knapsack(idx+1, c1, w[idx]+c2);
    return dp[idx][c1][c2] = (p1 | p2);
}

int main()
{
    int n, aux;
    cin >> n;
    string mystring;
    getchar();
    while(n--) {
        w.clear();
        getline(cin, mystring);
        istringstream iss(mystring);
        while (iss >> aux) {
            w.push_back(aux);
        }
        m = w.size();

        memset(dp, -1, sizeof dp);
        if (knapsack(0, 0, 0)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
