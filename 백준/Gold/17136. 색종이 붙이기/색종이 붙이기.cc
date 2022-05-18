#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int type_remain[6] = { 0,5,5,5,5,5 };
int remain_zero = 0, mincnt = 1e9;
bool chk(vector<vector<int>> &graph, const int &y, const int &x, const int &size) {
    if (x + size > 10 || y + size > 10 || type_remain[size] == 0) return false;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (graph[i][j] == 0) return false;
        }
    }
    return true;
}
void update(vector<vector<int>> &graph, const int &y, const int &x, const int &size, const bool &put_status) {
    put_status == true ? type_remain[size]-- : type_remain[size]++;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            graph[i][j] = (put_status == true) ? 0 : 1;
        }
    }
    (put_status == true) ? remain_zero -= pow(size, 2) : remain_zero += pow(size, 2);
}
void dfs(vector<vector<int>> &graph, int y, int x, const int &depth) {
    if (remain_zero == 0) {
        mincnt = min(mincnt, depth);
        return;
    }
    for (int i = y; i < 10; i++) {
        for (int j = x; j < 10; j++) {
            if (graph[i][j] == 1) {
                for (int size = 5; size > 0; size--) {
                    if (chk(graph, i, j, size)) {
                        update(graph, i, j, size, true);
                        dfs(graph, i, j, depth + 1);
                        update(graph, i, j, size, false);
                    }
                }
                return;
            }
            if (j == 9) x = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> graph(10, vector <int>(10, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) remain_zero++;
        }
    }
    if (remain_zero != 0) dfs(graph, 0, 0, 0);
    else mincnt = 0;
    mincnt == 1e9 ? cout << "-1\n" : cout << mincnt << "\n";
    return 0;
}