#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
pll operator- (pll a, pll b) {
    return { a.first - b.first, a.second - b.second };
}
int CCW(const pll &x, const pll &y, const pll &z) {
    ll ret = x.first * y.second + y.first * z.second + z.first * x.second;
    ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}
double CCW2(const pll &x, const pll &y, const pll &z) {
    ll ret = x.first * y.second + y.first * z.second + z.first * x.second;
    ret -= (x.second * y.first + y.second * z.first + z.second * x.first);
    return fabs(double(ret) / 2.0);
}
void sorting(vector<pll> &v) {
    sort(v.begin(), v.end(), [&](const pll a, const pll b) {
        if (a.second == b.second) return a.first < b.first; else return a.second < b.second; });
    sort(v.begin() + 1, v.end(), [&](const pll a, const pll b) {
        double deg_a = atan2(a.second - v[0].second, a.first - v[0].first);
        double deg_b = atan2(b.second - v[0].second, b.first - v[0].first);
        if (deg_a < deg_b) return true;
        else if (fabs(deg_a - deg_b) < 1e-14) {
            function<ll(pll, pll)> dist2 = [&](pll a, pll b) {
                return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
            };
            return dist2(v[0], a) < dist2(v[0], b);
        }
        else return false;
        });
}
void convexhull(vector<pll> &src, vector<pll> &tar, ll sz) {
    tar.push_back(src[0]);
    tar.push_back(src[1]);
    int idx = 2; pll next = src[idx];
    while (idx != sz) {
        while (tar.size() >= 2) {
            pll first, second;
            second = tar.back();
            tar.pop_back();
            first = tar.back();
            next = src[idx];
            if (CCW(first, second, next) > 0) {
                tar.push_back(second);
                break;
            }
        }
        tar.push_back(next);
        idx++;
    }
}
bool inside(const vector<pll> &v, const pll &p) {
    int vsize = v.size();
    double ret1 = 0.0, ret2 = 0.0;
    for (int i = 1; i < vsize; i++) {
        ret1 += CCW2(v[0], v[i - 1], v[i]);
    }
    for (int i = 0; i < vsize; i++) {
        ret2 += CCW2(p, v[i % vsize], v[(i + 1) % vsize]);
    }
    if (vsize != 0 && fabs(fabs(ret1) - fabs(ret2)) < 1e-14) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pll> v1(n), v2(m); vector<pll> bl, wh;
        for (int i = 0; i < n; i++) {
            cin >> v1[i].first >> v1[i].second;
        }
        for (int i = 0; i < m; i++) {
            cin >> v2[i].first >> v2[i].second;
        }
        sorting(v1);
        sorting(v2);
        if (n > 2) convexhull(v1, bl, n);
        if (m > 2) convexhull(v2, wh, m);
        bool ret = true;
        if (n + m == 2) ret = true;
        else if (n + m == 3) {
            auto temp = v1;
            temp.insert(temp.end(), v2.begin(), v2.end());
            if (temp[0].first == temp[1].first && temp[1].first - temp[2].first) { ret = false; break; }
            double grad1 = (temp[1].second - temp[0].second) / static_cast<double>((temp[1].first - temp[0].first));
            double grad2 = (temp[2].second - temp[1].second) / static_cast<double>((temp[2].first - temp[1].first));
            if (fabs(grad1 - grad2) < 1e-14) ret = false;
            else ret = true;
        }
        else if (n == 2 && m == 2) {
            ll a = v1[0].second - v1[1].second, b = v1[1].first - v1[0].first, c = v1[0].first * v1[1].second - v1[0].second * v1[1].first;
            ll ret1 = a * v2[0].first + b * v2[0].second + c, ret2 = a * v2[1].first + b * v2[1].second + c;
            if (ret1 > 0) ret1 = 1;
            else if (ret1 < 0) ret1 = -1;
            if (ret2 > 0) ret2 = 1;
            else if (ret2 < 0) ret2 = -1;
            if (ret1 * ret2 > 0) ret = true;
            else if (ret1 * ret2 == 0) {
                if (ret1 == 0 && ret2 != 0) {
                    if (min(v1[0].first, v1[1].first) < v2[0].first && v2[0].first < max(v1[0].first, v1[1].first)) ret = false;
                    else ret = true;
                }
                else if (ret1 != 0 && ret2 == 0) {
                    if (min(v1[0].first, v1[1].first) < v2[1].first && v2[1].first < max(v1[0].first, v1[1].first)) ret = false;
                    else ret = true;
                }
                else {
                    if (min(v1[0].first, v1[1].first) > max(v2[0].first, v2[1].first) || max(v1[0].first, v1[1].first) < min(v2[0].first, v2[1].first)) ret = true;
                    else ret = false;
                }
            }
            else ret = false;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (inside(wh, v1[i])) ret = false;
                if (!ret) break;
            }
            if (ret) {
                for (int i = 0; i < m; i++) {
                    if (inside(bl, v2[i])) ret = false;
                    if (!ret) break;
                }
            }
        }
        ret == true ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}