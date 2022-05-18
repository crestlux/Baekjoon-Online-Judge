#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret = INT_MIN;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < N; i++) {
        ret = max(ret, v[i] * (i + 1));
    }
    cout << ret << "\n";
    return 0;
}