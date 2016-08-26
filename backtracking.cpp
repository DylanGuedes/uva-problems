#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int n;

bool is_solution(int idx)
{
    if (idx == pow(10, n))
        return false;
    return true;
}

void process_solution(int idx)
{
    string response = to_string(idx);
    int zeros = n-response.size();
    FOR(i, 0, zeros) printf("0");
    printf("%d\n", idx);
}

void backtrack(int idx)
{
    if (is_solution(idx)) {
        process_solution(idx);
        backtrack(idx+1);
    }
}

int main()
{
    while (cin >> n) {
        backtrack(0);
    }
    return 0;
}
