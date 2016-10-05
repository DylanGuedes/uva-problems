#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

class book {
public:
        string name, author;
        book(string _name, string _author) : author(_author), name(_name) { }
        book() { }
};

vector<book> books;

bool myfunc(book b1, book b2)
{
        if (b1.author == b2.author)
                return b1.name < b2.name;
        else
                return b1.author < b2.author;
}

int main()
{
        ios::sync_with_stdio(false);
        string mystring;
        book b;
        while (getline(cin, mystring)) {
                if (mystring == "END")
                        break;
                else {
                        string nam = "";
                        istringstream iss(mystring);
                        string buf = "";
                        string spac = " ";
                        while (iss >> buf) {
                                if (buf == "by")
                                        break;
                                nam.append(spac);
                                nam.append(buf);
                        }
                        b.name = nam;
                        string auth = "";
                        while (iss >> buf) {
                                auth.append(buf);
                                auth.append(spac);
                        }

                        b.author = auth;
                        books.push_back(b);
                }

        }
        sort(books.begin(), books.end(), myfunc);
        map<string, int> out;
        for (auto it : books) {
                out.emplace(it.name, 1);
        }
        while (cin >> mystring) {
                if (mystring == "END")
                        break;
                else {
                        if (mystring == "BORROW") {
                                getline(cin, mystring);
                                out[mystring] = 0;
                        } else if (mystring == "RETURN") {
                                getline(cin, mystring);
                                out[mystring] = 1;
                        } else if (mystring == "SHELVE") {
                                int books_size = books.size();
                                FOR(i, 0, books_size) {
                                        FOR(j, i+1, books_size) {
                                                if (out[books[i].name]) {
                                                        if (out[books[j].name]) {
                                                                cout << "Put " << books[j].name << " after " << books[i].name << "\n";
                                                                break;
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
        cout << "END\n";
        return 0;
}
