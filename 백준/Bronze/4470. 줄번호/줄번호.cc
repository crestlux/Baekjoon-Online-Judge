#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; ++i) {
        string s1;
        getline(cin, s1);
        cout << i << ". " << s1 << "\n";
    }
    return 0;
}