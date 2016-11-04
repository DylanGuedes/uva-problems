#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        char buf;
        int qtd;
        string indexes;
        string mystring;
        getline(cin, mystring);
        bool flag=false;
        while (1) {
                while (getline(cin, mystring)) {
                        if (mystring.empty()) {
                                break;
                        } else {
                                flag=false;
                        }
                        istringstream iss(mystring);
                        iss >> qtd;
                        iss >> indexes;
                        rep(i, 0, 10) {
                                graph[i][10+i]=1;
                        }
                        rep(i, 0, 10) {
                                graph[i][100]=1;
                        }
                        rep(i, 0, 26) {
                                graph[26+i][101]=1;
                        }
                        for (auto it : indexes) {
                                graph[10+it][19+buf-'a'+26]=1;
                                graph[19+buf-'a'+26][19+buf-'a']=qtd;
                        }
                        iss >> buf;
                }

                cout << karp

                if (flag)
                        return 0;
                else
                        flag=1;
        }
        return 0;
}
