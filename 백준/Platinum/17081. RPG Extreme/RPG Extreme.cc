#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
class Game;
class Player {
private:
    int maxhp = 20, curhp = 20, str = 2, def = 2, exp = 0, lv = 1;
    int y = 0, x = 0, start_y = 0, start_x = 0;
    int weapon = 0, armor = 0;
    unordered_map<string, bool> accessory;
    friend Game;
public:
    Player() {
        accessory.insert({ "HR", false });
        accessory.insert({ "RE", false });
        accessory.insert({ "CO", false });
        accessory.insert({ "EX", false });
        accessory.insert({ "DX", false });
        accessory.insert({ "HU", false });
        accessory.insert({ "CU", false });
    }
    bool sufferDamage(int dmg) { //returns true if player has been killed
        curhp -= dmg;
        if (curhp <= 0) { curhp = 0; return true; };
        return false;
    }

    int getStr() const { return str + weapon; }
    int getDef() const { return def + armor; }
    int getAccessoryCount() const {
        int cnt = 0;
        for (auto it = accessory.begin(); it != accessory.end(); ++it) {
            if (it->second) cnt++;
        }
        return cnt;
    }

    void setHp(const int &val) {
        if (val <= maxhp) curhp = val;
        else [[unlikely]] assert(0);
    }
    void obtainHp(const int &&val) { curhp += val; if (curhp > maxhp) curhp = maxhp; }
    void obtainWeapon(int &wstr) { weapon = wstr; }
    void obtainArmor(int &adef) { armor = adef; }
    bool obtainAccessory(string &type) { //returns true if accessory is obtainable
        if (getAccessoryCount() >= 4) return false;
        if (type == "HR")  accessory["HR"] = true;
        else if (type == "RE") accessory["RE"] = true;
        else if (type == "CO") accessory["CO"] = true;
        else if (type == "EX") accessory["EX"] = true;
        else if (type == "DX") accessory["DX"] = true;
        else if (type == "HU") accessory["HU"] = true;
        else if (type == "CU") accessory["CU"] = true;
        return true;
    }
    void obtainExp(int &&gain) {
        int up = 5 * lv;
        if (accessory["EX"]) gain *= 1.2;
        if (up <= gain + exp) { ++lv; exp = 0; maxhp += 5; str += 2; def += 2; curhp = maxhp; }
        else exp += gain;
    }
    void printPlayerStatus() const {
        cout << "LV : " << lv << "\n";
        cout << "HP : " << curhp << "/" << maxhp << "\n";
        cout << "ATT : " << str << "+" << weapon << "\n";
        cout << "DEF : " << def << "+" << armor << "\n";
        cout << "EXP : " << exp << "/" << lv * 5 << "\n";
    }
};

class Monster {
private:
    string name = "";
    int maxhp = 0, curhp = 0, str = 0, def = 0, exp = 0;
    int y = 0, x = 0;
    friend Game;
public:
    Monster(int y, int x, string S, int W, int A, int H, int E) {
        this->y = y, this->x = x;
        name = S; str = W; def = A; maxhp = H; curhp = H; exp = E;
    }
    Monster() {}
    string getName() const { return name; }
    int getStr() const { return str; }
    int getDef() const { return def; }
    void setHp(int val) {
        if (val <= maxhp) curhp = val;
        else [[unlikely]] assert(0);
    }
    bool sufferDamage(int dmg) { //returns true if monster has been killed
        curhp -= dmg;
        if (curhp <= 0) { curhp = 0; return true; };
        return false;
    }
};

class Item {
private:
    int y = 0, x = 0, item_val = 0; char item_type = '\0'; string accessory_type = "";
    friend Game;
public:
    Item(int R, int C, char T, int S) { y = R; x = C; item_type = T; item_val = S; }
    Item(int R, int C, char T, string S) { y = R; x = C; item_type = T; accessory_type = S; }
    Item() {}
};

class Game {
private:
    int N, M; bool finished = false, death = false;
    vector<Monster> mon; vector<Item> itm;
    int monster_cnt = 0, item_cnt = 0;
    string S; vector<vector<char>> graph;
    int turns = 0;
public:
    void graphInput(Player &p1) {
        cin >> N >> M;
        graph.resize(N + 1, vector<char>(M + 1));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                auto &cur = graph[i][j];
                cin >> cur;
                if (cur == '@') { cur = '.'; p1.x = j, p1.y = i; p1.start_x = j; p1.start_y = i; }
                else if (cur == '&' || cur == 'M') monster_cnt++;
                else if (cur == 'B') item_cnt++;
            }
        }
    }
    void traceInput() { cin >> S; }
    void monsterInput() {
        for (int i = 0; i < monster_cnt; ++i) {
            string S; int y, x, W, A, H, E;
            cin >> y >> x >> S >> W >> A >> H >> E;
            Monster m1(y, x, S, W, A, H, E);
            mon.emplace_back(m1);
        }
    }
    void itemInput() {
        for (int i = 0; i < item_cnt; ++i) {
            int y, x; char item_type;
            cin >> y >> x >> item_type;
            if (item_type == 'W' || item_type == 'A') {
                int item_val;
                cin >> item_val;
                Item i1(y, x, item_type, item_val);
                itm.emplace_back(i1);
            }
            else if (item_type == 'O') {
                string accessory_type;
                cin >> accessory_type;
                Item i2(y, x, item_type, accessory_type);
                itm.emplace_back(i2);
            }
        }
    }
    void printMap() const {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cout << graph[i][j];
            }
            cout << "\n";
        }
    }
    void printResult(const Player &p1) const {
        cout << "Passed Turns : " << turns << "\n";
        p1.printPlayerStatus();
    }
    void battle(Player &p1, Monster &m1, bool &&boss = false) {
        auto mk = [&]() {
            graph[p1.y][p1.x] = '.';
            p1.obtainExp(move(m1.exp));
            if (p1.accessory["HR"]) p1.obtainHp(3);
            if (boss) {
                graph[p1.y][p1.x] = '@';
                printMap();
                printResult(p1);
                cout << "YOU WIN!\n";
                finished = true;
            }
        };
        auto pk = [&]() {
            if (boss) killed(p1, "boss", move(m1));
            else killed(p1, "monster", move(m1));
        };

        bool first_hit = true; bool player_killed = false, monster_killed = false;
        if (boss) {
            if (p1.accessory["HU"]) {
                p1.setHp(p1.maxhp);
            }
        }
        while (!player_killed && !monster_killed) {
            if (first_hit) {
                if (p1.accessory["CO"] && p1.accessory["DX"]) monster_killed = m1.sufferDamage(max(1, p1.getStr() * 3 - m1.getDef()));
                else if (p1.accessory["CO"] && !p1.accessory["DX"]) monster_killed = m1.sufferDamage(max(1, p1.getStr() * 2 - m1.getDef()));
                else monster_killed = m1.sufferDamage(max(1, p1.getStr() - m1.getDef()));
                if (monster_killed) {
                    mk();
                    break;
                }
                if ((boss && !p1.accessory["HU"]) || !boss) {
                    player_killed = p1.sufferDamage(max(1, m1.getStr() - p1.getDef()));
                }
                if (player_killed) {
                    pk();
                    break;
                }
                first_hit = false;
            }
            else {
                monster_killed = m1.sufferDamage(max(1, p1.getStr() - m1.getDef()));
                if (monster_killed) {
                    mk();
                    break;
                }
                player_killed = p1.sufferDamage(max(1, m1.getStr() - p1.getDef()));
                if (player_killed) {
                    pk();
                    break;
                }

            }

        }

    }
    bool killed(Player &p1, string &&cause, Monster &&m1 = Monster()) {
        if (p1.accessory["RE"]) {
            p1.accessory["RE"] = false;
            p1.x = p1.start_x; p1.y = p1.start_y;
            p1.setHp(p1.maxhp);
            m1.setHp(m1.maxhp);
            death = false;
            return false;
        }
        printMap();
        printResult(p1);
        if (cause == "spike") cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP..\n";
        else if (cause == "monster" || cause == "boss") cout << "YOU HAVE BEEN KILLED BY " << m1.name << "..\n";
        death = true;
        finished = true;
        return true;
    }
    bool outOfRange(int y, int x) { return (y <= 0 || y > N || x <= 0 || x > M); }
    void mov(Player &p1) {
        for (auto it = S.begin(); (it != S.end() && !finished); ++it) {
            if (*it == 'U' && !outOfRange(p1.y - 1, p1.x) && graph[p1.y - 1][p1.x] != '#') p1.y--;
            else if (*it == 'D' && !outOfRange(p1.y + 1, p1.x) && graph[p1.y + 1][p1.x] != '#') p1.y++;
            else if (*it == 'L' && !outOfRange(p1.y, p1.x - 1) && graph[p1.y][p1.x - 1] != '#') p1.x--;
            else if (*it == 'R' && !outOfRange(p1.y, p1.x + 1) && graph[p1.y][p1.x + 1] != '#') p1.x++;
            auto &cur = graph[p1.y][p1.x];
            const auto &cur_x = p1.x, &cur_y = p1.y;
            if (cur == '.') {
                ++turns;
            }
            else if (cur == '#') [[unlikely]] {
                assert(0);
            }
            else if (cur == 'B') {
                ++turns;
                Item i1;
                for (auto &e : itm)
                    if (e.y == cur_y && e.x == cur_x) i1 = e;
                if (i1.item_type == 'W') {
                    p1.obtainWeapon(i1.item_val);
                    cur = '.';
                }
                else if (i1.item_type == 'A') {
                    p1.obtainArmor(i1.item_val);
                    cur = '.';
                }
                else if (i1.item_type == 'O') {
                    p1.obtainAccessory(i1.accessory_type);
                    cur = '.';
                }
                else [[unlikely]] assert(0);
            }
            else if (cur == '^') {
                ++turns;
                if (p1.accessory["DX"]) death = p1.sufferDamage(1);
                else death = p1.sufferDamage(5);
                if (death) death = killed(p1, "spike");
            }
            else if (cur == '&') {
                ++turns;
                Monster m1;
                for (auto &e : mon)
                    if (e.y == cur_y && e.x == cur_x) m1 = e;
                battle(p1, m1, false);
            }
            else if (cur == 'M') {
                ++turns;
                Monster m1;
                for (auto &e : mon)
                    if (e.y == cur_y && e.x == cur_x) m1 = e;
                battle(p1, m1, true);
            }
        }
        if (!death) graph[p1.y][p1.x] = '@';
        if (!finished) {
            printMap();
            printResult(p1);
            cout << "Press any key to continue." << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    Player p1; Game g;
    g.graphInput(p1);
    g.traceInput();
    g.monsterInput();
    g.itemInput();
    g.mov(p1);
    return 0;
}