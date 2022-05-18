#include <bits/stdc++.h>
using namespace std;
int maxval = -987654321; vector<int> tmp;
vector<vector<int>> movu(vector<vector<int>> v, int N) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = 0;
        if (tsize == 1) {
            v[0][x] = tmp[0];
            for (int i = cur + 1; i < N; i++) v[i][x] = 0;
            tmp.clear();
            continue;
        }
        else {
            for (int i = 0; i < tsize; i++) {
                if (i == tsize - 1) {
                    v[cur][x] = tmp[i];
                }
                else {
                    if (tmp[i] == tmp[i + 1]) {
                        v[cur][x] = tmp[i] + tmp[i + 1];
                        ++i;
                    }
                    else {
                        v[cur][x] = tmp[i];
                    }
                }
                cur++;
            }
            for (int i = cur; i < N; i++) v[i][x] = 0;
        }
        tmp.clear();
    }
    return v;
}
vector<vector<int>> movd(vector<vector<int>> v, int N) {
    for (int x = 0; x < N; x++) {
        for (int y = N - 1; y >= 0; y--) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = N - 1;
        if (tsize == 1) {
            v[N - 1][x] = tmp[0];
            for (int i = cur - 1; i >= 0; i--) v[i][x] = 0;
            tmp.clear();
            continue;
        }
        else {
            for (int i = 0; i < tsize; i++) {
                if (i == tsize - 1) {
                    v[cur][x] = tmp[i];
                }
                else {
                    if (tmp[i] == tmp[i + 1]) {
                        v[cur][x] = tmp[i] + tmp[i + 1];
                        ++i;
                    }
                    else {
                        v[cur][x] = tmp[i];
                    }
                }
                cur--;
            }
            for (int i = cur; i >= 0; i--) v[i][x] = 0;
        }
        tmp.clear();
    }
    return v;
}
vector<vector<int>> movl(vector<vector<int>> v, int N) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = 0;
        if (tsize == 1) {
            v[y][0] = tmp[0];
            for (int i = cur + 1; i < N; i++) v[y][i] = 0;
            tmp.clear();
            continue;
        }
        else {
            for (int i = 0; i < tsize; i++) {
                if (i == tsize - 1) {
                    v[y][cur] = tmp[i];
                }
                else {
                    if (tmp[i] == tmp[i + 1]) {
                        v[y][cur] = tmp[i] + tmp[i + 1];
                        ++i;
                    }
                    else {
                        v[y][cur] = tmp[i];
                    }
                }
                cur++;
            }
            for (int i = cur; i < N; i++) v[y][i] = 0;
        }
        tmp.clear();
    }
    return v;
}
vector<vector<int>> movr(vector<vector<int>> v, int N) {
    for (int y = 0; y < N; y++) {
        for (int x = N - 1; x >= 0; x--) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = N - 1;
        if (tsize == 1) {
            v[y][N - 1] = tmp[0];
            for (int i = cur - 1; i >= 0; i--) v[y][i] = 0;
            tmp.clear();
            continue;
        }
        else {
            for (int i = 0; i < tsize; i++) {
                if (i == tsize - 1) {
                    v[y][cur] = tmp[i];
                }
                else {
                    if (tmp[i] == tmp[i + 1]) {
                        v[y][cur] = tmp[i] + tmp[i + 1];
                        ++i;
                    }
                    else {
                        v[y][cur] = tmp[i];
                    }
                }
                cur--;
            }
            for (int i = cur; i >= 0; i--) v[y][i] = 0;
        }
        tmp.clear();
    }
    return v;
}
void recsolve(vector<vector<int>> v, int N, int depth) { //up, down, left, right
    if (depth == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                maxval = max(maxval, v[i][j]);
            }
        }
        return;
    }
    recsolve(movu(v, N), N, depth + 1);
    recsolve(movd(v, N), N, depth + 1);
    recsolve(movl(v, N), N, depth + 1);
    recsolve(movr(v, N), N, depth + 1);
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    vector<vector<int>> v(21, vector<int>(21, 0));
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    recsolve(v, N, 0);
    cout << maxval << "\n";
    return 0;
}