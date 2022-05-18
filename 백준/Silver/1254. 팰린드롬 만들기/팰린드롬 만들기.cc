#include <bits/stdc++.h>
using namespace std;
vector<int> buildPi(const string &N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else if (matched == 0) ++begin;
        else {
            begin += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return pi;
}
int overlap(const string &H, const string &N) {
    int n = H.size(), m = N.size();
    vector<int> pi = buildPi(N);
    int matched = 0, begin = 0;
    while (begin < n) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (begin + matched == n) return matched;
        }
        else if (matched == 0) ++begin;
        else {
            begin += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, rs1;
    cin >> s1;
    rs1 = s1;
    reverse(rs1.begin(), rs1.end());
    cout << (2 * s1.length()) - overlap(s1, rs1) << "\n";
    return 0;
}