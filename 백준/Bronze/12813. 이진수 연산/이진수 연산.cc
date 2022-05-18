#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    bitset<100000> a, b;
    cin >> a >> b;
    cout << (a & b) << "\n" << (a | b) << "\n" << (a ^ b) << "\n" << (~a) << "\n" << (~b) << "\n";
    return 0;
}