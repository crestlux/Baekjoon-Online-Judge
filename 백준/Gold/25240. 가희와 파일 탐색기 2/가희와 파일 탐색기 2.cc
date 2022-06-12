#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef struct finfo {
    string name = "";
    string owner = "";
    string owngrp = "";
    finfo() {}
    finfo(string n) { name = n; }
    bool operator == (const finfo &other) const {
        if (name == other.name) return true;
        return false;
    }
}finfo;
struct h {
    size_t operator()(const finfo &f) const {
        hash<string> hash_func;
        return hash_func(f.name);
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int U, F, Q;
    unordered_map<string, vector<string>> user_table;
    unordered_map<finfo, bitset<9>, h> file_table;
    cin >> U >> F;
    cin.ignore();
    for (int i = 0; i < U; ++i) {
        size_t pos = 0; vector<string> usrgrp;
        string parse, delim = ",", token, usr;
        getline(cin, parse);
        auto usrlen = parse.find(" ");
        usr = parse.substr(0, usrlen);
        usrgrp.push_back(usr);
        if (usrlen == string::npos) { user_table.insert({ usr, usrgrp }); continue; }
        else parse.erase(parse.begin(), parse.begin() + usrlen + 1);
        while ((pos = parse.find(delim)) != string::npos) {
            token = parse.substr(0, pos);
            usrgrp.push_back(token);
            parse.erase(0, pos + delim.length());
        }
        usrgrp.push_back(parse);
        user_table.insert({ usr, usrgrp });
    }
    for (int i = 0; i < F; ++i) {
        finfo f1; string pm_str;
        cin >> f1.name >> pm_str >> f1.owner >> f1.owngrp;
        file_table.insert({ f1, bitset<9>(stol(pm_str, nullptr, 8)) });
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string uname, fname, op;
        cin >> uname >> fname >> op;
        finfo find_target(fname);
        auto usrgrp = user_table[uname];
        auto target_it = file_table.find(find_target);
        if (target_it->first.owner == uname) {
            if (op == "R") cout << target_it->second[8] << "\n";
            else if (op == "W") cout << target_it->second[7] << "\n";
            else cout << target_it->second[6] << "\n";
        }
        else if (find(usrgrp.begin(), usrgrp.end(), target_it->first.owngrp) != usrgrp.end()) {
            if (op == "R") cout << target_it->second[5] << "\n";
            else if (op == "W") cout << target_it->second[4] << "\n";
            else cout << target_it->second[3] << "\n";
        }
        else {
            if (op == "R") cout << target_it->second[2] << "\n";
            else if (op == "W") cout << target_it->second[1] << "\n";
            else cout << target_it->second[0] << "\n";
        }
    }
    return 0;
}