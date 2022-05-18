#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using vapii4 = vector<array<pair<int, int>, 4>>;
vapii4 tet; int graph[501][501];
void preBuild() {
    tet = {
    {{{0,0}, {1,0}, {2,0}, {3,0}}}, {{{0,0}, {0,1}, {0,2}, {0,3}}},
    {{{0,0}, {1,0}, {0,1}, {1,1}}}, {{{0,0}, {0,1}, {0,2}, {1,2}}},
    {{{0,0}, {0,1}, {1,0}, {2,0}}}, {{{0,0}, {1,0}, {1,1}, {1,2}}},
    {{{0,0}, {1,0}, {2,0}, {2,-1}}}, {{{0,0}, {1,0}, {1,-1},{1,-2}}},
    {{{0,0}, {0,1}, {1,1}, {2,1}}}, {{{0,0}, {1,0}, {0,1}, {0,2}}},
    {{{0,0}, {1,0}, {2,0}, {2,1}}}, {{{0,0}, {0,1}, {1,1}, {1,2}}},
    {{{0,0}, {1,0}, {1,-1}, {2,-1}}}, {{{0,0}, {0,1}, {1,0}, {1,-1}}},
    {{{0,0}, {1,0}, {1,1}, {2,1}}}, {{{0,0}, {1,0}, {2,0}, {1,1}}},
    {{{0,0}, {0,1}, {0,2}, {1,1}}}, {{{0,0}, {1,0}, {1,-1} ,{1,1}}},
    {{{0,0}, {1,0}, {2,0}, {1,-1}}}
    };
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    preBuild();
    int N, M, sum = INT_MIN, cursum = 0;
    bool success = true;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            for (const auto &e : tet) {
                cursum = 0; success = true;
                for (int k = 0; k < 4; k++) {
                    int nx = x + e[k].first, ny = y + e[k].second;
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                        success = false;
                        break;
                    }
                    else cursum += graph[ny][nx];
                }
                if (success) sum = max(sum, cursum);
            }
        }
    }
    cout << sum << "\n";
    return 0;
}