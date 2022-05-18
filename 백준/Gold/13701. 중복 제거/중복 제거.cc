#include <bits/stdc++.h>
using namespace std;
int arr[1 << 20u];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int input;
    while (cin >> input) {
        int q = input >> 5;
        int r = 1 << (input % 32);
        if (!(arr[q] & r)) {
            arr[q] += r;
            cout << input << " ";
        }
    }
    cout << "\n";
    return 0;
}