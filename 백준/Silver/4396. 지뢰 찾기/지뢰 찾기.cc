#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0,-1,1,-1,1,-1,1 }, dy[] = { -1,1,0,0,-1,-1,1,1 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<char>> mines(N, vector<char>(N)), opened(N, vector<char>(N)), num(N, vector<char>(N)), ret(N, vector<char>(N, '.'));
    for (auto &e1 : mines) {
        for (auto &e2 : e1) cin >> e2;
    }
    for (auto &e1 : opened) {
        for (auto &e2 : e1) cin >> e2;
    }
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            int mines_num = 0;
            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                else if (mines[ny][nx] == '*') [[likely]] mines_num++;
            }
            num[y][x] = mines_num + '0';
        }
    }
    bool exploded = false;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (opened[y][x] == 'x') {
                ret[y][x] = num[y][x];
                if (mines[y][x] == '*') exploded = true;
            }
        }
    }
    if (exploded) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (mines[y][x] == '*') ret[y][x] = '*';
            }
        }
    }
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << ret[y][x];
        }
        cout << "\n";
    }
    return 0;
}