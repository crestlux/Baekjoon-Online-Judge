#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int N, K, L, t = 0;
class Coord {
public:
    int y = 1, x = 1;
    Coord(int a, int b) :y(a), x(b) {}
    Coord() {}
    void next(char &dir) {
        if (dir == 'U') y--;
        else if (dir == 'D') y++;
        else if (dir == 'L') x--;
        else if (dir == 'R') x++;
        else [[unlikely]] assert(0);
    }
    auto operator<=> (const Coord &c) const = default;
};
deque<Coord> s; set<Coord> apple; bool finished = false;
vector<char> dir = { 'R', 'U', 'L', 'D' }; int curdir = 0;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    s.emplace_front(Coord());
    cin >> N >> K;
    while (K--) {
        int p, q;
        cin >> p >> q;
        apple.insert(Coord(p, q));
    }
    auto mov = [&]() {
        auto f = s.front();
        f.next(dir[curdir]);
        for (auto &e : s) {
            if (e == f) {
                finished = true;
                break;
            }
        }
        if (f.x <= 0 || f.x > N || f.y <= 0 || f.y > N) finished = true;
        if (finished) return true;
        s.emplace_front(f);
        auto it = apple.find(Coord(f.y, f.x));
        if (it == apple.end()) s.pop_back();
        else apple.erase(it);
        return false;
    };
    cin >> L;
    while (L--) {
        int rt_time = 0; char rt_dir = 0;
        cin >> rt_time >> rt_dir;
        for (int i = t; i < rt_time; ++i) {
            t++;
            if (mov()) break;
        }
        if (finished) break;
        if (rt_dir == 'L') {
            curdir = (curdir + 1) % 4;
        }
        else if (rt_dir == 'D') {
            curdir = (curdir + 4 - 1) % 4;
        }
        else [[unlikely]] assert(0);
    }
    while (!finished) {
        t++;
        mov();
    }
    cout << t << "\n";
    return 0;
}