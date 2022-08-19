#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
constexpr string_view precomputation("AAE3HHIIJLLJMMOOS2TTUUVVWWXXYYZ5002S3E5Z88");
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<char, char> hm;
    constexpr int psz = precomputation.size();
    for (int i = 0; i < psz; i += 2)  hm[precomputation[i]] = precomputation[i + 1];
    string s, rev;
    while (cin >> s) {
        rev = s;
        ranges::reverse(rev);
        bool pal = (s == rev), mir = true;
        int ssz = s.size();
        for (int i = 0; i < (ssz + 1) >> 1; ++i) {
            if (hm[s[i]] == s[ssz - i - 1]) continue;
            else {
                mir = false;
                break;
            }
        }
        cout << s;
        if (pal and mir) cout << " -- is a mirrored palindrome.\n";
        else if (pal and !mir) cout << " -- is a palindrome.\n";
        else if (!pal and mir) cout << " -- is a mirrored string.\n";
        else cout << " -- is not a palindrome.\n";
        cout << "\n";
    }
    return 0;
}