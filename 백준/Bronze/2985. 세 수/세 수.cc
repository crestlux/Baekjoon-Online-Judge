#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B, C; char op1, op2;
    cin >> A >> B >> C;
    if (A + B == C) { op1 = '+'; op2 = '='; }
    else if (A - B == C) { op1 = '-'; op2 = '='; }
    else if (A * B == C) { op1 = '*'; op2 = '='; }
    else if (A / B == C) { op1 = '/'; op2 = '='; }
    else if (A == B + C) { op1 = '='; op2 = '+'; }
    else if (A == B - C) { op1 = '='; op2 = '-'; }
    else if (A == B * C) { op1 = '='; op2 = '*'; }
    else if (A == B / C) { op1 = '='; op2 = '/'; }
    cout << A << op1 << B << op2 << C << "\n";
    return 0;
}