#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
string alph = "AVXSWDFGUHJKNBIOQEARYCQZTZ", num = "9`12345678";
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string input;
    while (getline(cin, input)) {
        for (auto &e : input) {
            if (isupper(e)) cout << alph[e - 'A'];
            else if (isdigit(e)) cout << num[e - '0'];
            else if (e == ' ') cout << ' ';
            else if (e == '[') cout << 'P';
            else if (e == ']') cout << '[';
            else if (e == '\\') cout << ']';
            else if (e == ';') cout << 'L';
            else if (e == '\'') cout << ';';
            else if (e == ',') cout << 'M';
            else if (e == '.') cout << ',';
            else if (e == '/') cout << '.';
            else if (e == '-') cout << '0';
            else if (e == '=') cout << '-';
            else assert(0);
        }
        cout << "\n";
    }
    return 0;
}