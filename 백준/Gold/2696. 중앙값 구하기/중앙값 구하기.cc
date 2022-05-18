#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, M;
    cin >> T;
    while (T--) {
        priority_queue<int> maxh;
        priority_queue<int, vector<int>, greater<int>>minh;
        cin >> M;
        cout << ((M + 1) >> 1) << "\n";
        for (int i = 1; i <= M; i++) {
            int temp;
            cin >> temp;
            if (maxh.size() == 0) maxh.push(temp);
            else {
                if (minh.size() >= maxh.size()) maxh.push(temp);
                else minh.push(temp);
                if (maxh.top() > minh.top()) {
                    int x = maxh.top(), y = minh.top();
                    maxh.pop(); minh.pop();
                    maxh.push(y); minh.push(x);
                }
            }
            if (i & 1) {
                cout << maxh.top() << " ";
                if ((i - 19) % 20 == 0) cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}