#import <bits/stdc++.h>
using namespace std;main(){string s;regex r(R"(BUG)");while(getline(cin,s)){while(regex_search(s,r))s=regex_replace(s,r,"");cout<<s<<"\n";}}