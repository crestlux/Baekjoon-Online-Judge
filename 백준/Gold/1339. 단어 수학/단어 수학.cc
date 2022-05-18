#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; string s1; ll alph[26] = { 0, }, ret = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s1;
        int slen = s1.length();
        ll cnt = 1;
        for (int j = slen - 1; j >= 0; j--) {
            alph[s1[j] - 'A'] += cnt;
            cnt *= 10LL;
        }
    }
    sort(alph, alph + 26, [&](const ll &a, const ll &b) {return a > b; });
    for (int i = 0; i < 10; i++) {
        ret += alph[i] * (9 - i);
    }
    cout << ret << "\n";
    return 0;
}