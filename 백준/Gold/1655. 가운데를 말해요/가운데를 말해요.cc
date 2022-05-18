#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, num; priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (maxpq.size() == 0) maxpq.push(num);
        else {
            if (maxpq.size() > minpq.size()) minpq.push(num);
            else maxpq.push(num);
            if (maxpq.top() > minpq.top()) {
                int p = maxpq.top(), q = minpq.top();
                maxpq.pop(); minpq.pop();
                maxpq.push(q); minpq.push(p);
            }
        }
        cout << maxpq.top() << "\n";
    }
    return 0;
}