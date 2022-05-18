#include <bits/stdc++.h>
using namespace std;
bool doublecmp(auto a, auto b) {
    if (fabs(a - b) < DBL_EPSILON) return true;
    else return false;
}
void validtest(vector<int> &prog, int N, int p, int q) {
    bool chkvalid = true;
    for (int i = 0; i < N - 1; i++) {
        if (prog[i] * p + q == prog[i + 1]) continue;
        else { chkvalid = false; break; }
    }
    if (!chkvalid) cout << "B\n";
    else cout << prog.back() * p + q << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, p = 0, q = 0;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    if (N == 1) cout << "A\n";
    else if (N == 2) {
        if (v[0] == v[1]) cout << v[0] << "\n";
        else cout << "A\n";
    }
    else {
        if (v[0] == v[1]) {
            p = 0; q = v[1];
            validtest(v, N, p, q);
        }
        else {
            p = (v[1] - v[2]) / (v[0] - v[1]);
            q = v[1] - p * v[0];
            if (v.size() == 3) {
                if (doublecmp(p, ((v[1] - v[2]) / (v[0] - double(v[1]))))) cout << v.back() * p + q << "\n";
                else cout << "B\n";
            }
            else {
                validtest(v, N, p, q);
            }
        }
    }
    return 0;
}