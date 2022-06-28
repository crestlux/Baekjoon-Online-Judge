#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int num, sum = 0;
    while (cin >> num) sum += num;
    cout << sum << "\n";
    return 0;
}