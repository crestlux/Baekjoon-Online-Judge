#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1;
    cin >> s1;
    s1.erase(unique(s1.begin(),s1.end()),s1.end());
    cout << s1 << "\n";
    return 0;
}