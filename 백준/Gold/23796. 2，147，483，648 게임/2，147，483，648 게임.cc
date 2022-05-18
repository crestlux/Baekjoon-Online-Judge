#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> tmp;
constexpr int bsize = 8;
void movu(vector<vector<ll>> &v) {
    for (int x = 0; x < bsize; x++) {
        for (int y = 0; y < bsize; y++) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = 0;
        if (tsize == 1) {
            v[0][x] = tmp[0];
            for (int i = cur + 1; i < bsize; i++) v[i][x] = 0;
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
            for (int i = cur; i < bsize; i++) v[i][x] = 0;
        }
        tmp.clear();
    }
}
void movd(vector<vector<ll>> &v) {
    for (int x = 0; x < bsize; x++) {
        for (int y = bsize - 1; y >= 0; y--) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = bsize - 1;
        if (tsize == 1) {
            v[bsize - 1][x] = tmp[0];
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
}
void movl(vector<vector<ll>> &v) {
    for (int y = 0; y < bsize; y++) {
        for (int x = 0; x < bsize; x++) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = 0;
        if (tsize == 1) {
            v[y][0] = tmp[0];
            for (int i = cur + 1; i < bsize; i++) v[y][i] = 0;
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
            for (int i = cur; i < bsize; i++) v[y][i] = 0;
        }
        tmp.clear();
    }
}
void movr(vector<vector<ll>> &v) {
    for (int y = 0; y < bsize; y++) {
        for (int x = bsize - 1; x >= 0; x--) {
            if (v[y][x] != 0) tmp.push_back(v[y][x]);
        }
        int tsize = tmp.size(), cur = bsize - 1;
        if (tsize == 1) {
            v[y][bsize - 1] = tmp[0];
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
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    char c;
    vector<vector<ll>> v(bsize, vector<ll>(bsize, 0LL));
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            cin >> v[i][j];
        }
    }
    cin >> c;
    if (c == 'U') movu(v);
    else if (c == 'D') movd(v);
    else if (c == 'L') movl(v);
    else movr(v);
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}