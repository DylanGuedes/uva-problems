#include <iostream>

using namespace std;

#define FOR(i, j, k) for (int i=j;i<k;++i)

int main()
{
    string mystring;
    int n, k;
    while (cin >> n >> k) {
        FOR(i, 0, n) {
            cin >> vel[i];
        }
        FOR(i, 0, n) {
            getline(cin, mystring);
            isstream myiss(mystring);
            int aux;
            vector<int> myv;
            while (myiss >> aux) {
                myv.push_back(aux);
            }
        }
    }
    return 0;
}
