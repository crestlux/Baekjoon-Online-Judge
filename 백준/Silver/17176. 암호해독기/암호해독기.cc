#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; string s1;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    cin.ignore();
    getline(cin, s1);
    sort(v.begin(), v.end());
    sort(s1.begin(), s1.end());
    bool b = true;
    for (int i = 0; i < N; i++) {
        if (s1[i] == ' ' && v[i] == 0) { continue; }
        else if ((s1[i] >= 'a' && s1[i] <= 'z') && (v[i] == int(s1[i]) - 'a' + 27)) { continue; }
        else if ((s1[i] >= 'A' && s1[i] <= 'Z') && (v[i] == int(s1[i]) - 'A' + 1)) { continue; }
        else { b = false; break; }
    }
    b ? cout << "y\n" : cout << "n\n";
    return 0;
}