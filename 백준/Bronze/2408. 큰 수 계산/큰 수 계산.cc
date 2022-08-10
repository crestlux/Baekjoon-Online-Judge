//using FFT from https://cp-algorithms.com/algebra/fft.html
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
namespace arithmetic {
    using namespace numbers;
    using cd = complex<double>;
    using vi = vector<int>;

    //using forward declaration for switch expression by sign
    string addition(string A, string B);
    string subtraction(string s1, string s2);

    void fft(vector<cd> &a, bool invert) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * pi / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                cd w(1);
                for (int j = 0; j < len / 2; j++) {
                    cd u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert) {
            for (cd &x : a) x /= n;
        }
    }
    vi multiply(vi const &a, vi const &b) {
        vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while (n < int(a.size()) + int(b.size())) n <<= 1;
        fa.resize(n);
        fb.resize(n);
        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; i++) fa[i] *= fb[i];
        fft(fa, true);
        vi result(n);
        for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
        int carry = 0;
        for (int i = 0; i < n; i++) {
            result[i] += carry;
            carry = result[i] / 10;
            result[i] %= 10;
        }
        return result;
    }
    string multiplication(string A, string B) {
        if (A == "0" || B == "0") return "0"; //Regarding that 0 doesn't have leading sign symbol
        else {
            bool ret_negative = (A[0] == '-') ^ (B[0] == '-');
            if (A[0] == '-') A.erase(A.begin());
            if (B[0] == '-') B.erase(B.begin());
            size_t Alen = A.length(), Blen = B.length();
            vi v1(Alen), v2(Blen);
            for (size_t i = 0; i < Alen; i++) v1[i] = A[Alen - i - 1] - '0';
            for (size_t i = 0; i < Blen; i++) v2[i] = B[Blen - i - 1] - '0';
            auto retv = multiply(v1, v2);
            int rsz = retv.size(), end = rsz - 1;
            for (int i = end; i >= 0; i--) {
                if (retv[i] == 0) continue;
                else { end = i; break; }
            }
            string ret = "";
            for (int i = end; i >= 0; i--) {
                ret += retv[i] + '0';
            }
            if (ret_negative) ret = "-" + ret;
            return ret;
        }
    }
    string addition(string A, string B) {
        bool one_negative = (A[0] == '-') ^ (B[0] == '-');
        bool both_negative = (A[0] == '-') & (B[0] == '-');
        bool ret_negative = false;
        string src_A = A, src_B = B;
        if (one_negative) { // Change exp to subtraction, careful to chk the order of them
            if (A[0] == '-') {
                A.erase(A.begin());
                return subtraction(B, A);
            }
            else {
                B.erase(B.begin());
                return subtraction(A, B);
            }
        }
        if (both_negative) {
            A.erase(A.begin());
            B.erase(B.begin());
            ret_negative = true;
        }
        string ret; int carry = 0, temp = 0;
        ranges::reverse(A);
        ranges::reverse(B);
        while (A.length() < B.length()) A += '0';
        while (A.length() > B.length()) B += '0';
        for (int i = 0; i < int(A.length()); i++) {
            temp = ((A[i] - '0') + (B[i] - '0') + carry) % 10;
            ret += to_string(temp);
            carry = ((A[i] - '0') + (B[i] - '0') + carry) / 10;
        }
        if (carry != 0) {
            ret += to_string(carry);
        }
        if (ret_negative) ret += "-";
        ranges::reverse(ret);
        return ret;
    }
    string subtraction(string A, string B) { // A - B
        if (A[0] != '-' and B[0] == '-') {
            B.erase(B.begin());
            return addition(A, B);
        }
        else if (A[0] == '-' and B[0] != '-') {
            A.erase(A.begin());
            auto ret = addition(A, B);
            ret = "-" + ret;
            return ret;
        }
        else if (A[0] == '-' and B[0] == '-') {
            A.erase(A.begin());
            B.erase(B.begin());
            return subtraction(B, A);
        }
        else {
            string ret; int borrow = 0, tmp = 0;
            bool ret_negative = false;
            if (A.length() < B.length()) ret_negative = true;
            else if (A.length() > B.length()) ret_negative = false;
            else ret_negative = (A.compare(B) < 0);
            ranges::reverse(A);
            ranges::reverse(B);
            while (A.length() < B.length()) A += '0';
            while (A.length() > B.length()) B += '0';
            if (ret_negative) swap(A, B);
            for (int i = 0; i < int(A.length()); i++) {
                tmp = (((A[i] - '0') - (B[i] - '0') - borrow) + 10) % 10;
                ret += to_string(tmp);
                borrow = ((A[i] - '0') - (B[i] - '0') - borrow < 0) ? 1 : 0;
            }
            if (borrow != 0) {
                assert(0);
            }
            for (auto it = ret.rbegin(); it != ret.rend();) {
                if (*it == '0') it = decltype(it){ ret.erase(next(it).base()) };
                else break;
            }
            ranges::reverse(ret);
            if (ret.empty()) ret += "0";
            if (ret_negative) ret = "-" + ret;
            return ret;
        }
    }
    string division(string A, string B) { // A/B = Q + r
        string ret, one = "1";
        if (B == "0") assert(0);
        if (A == "0") return "0";
        if (B == "1") return A;
        if (B == "-1") {
            if (A[0] == '-') {
                A.erase(A.begin());
                return A;
            }
            else return "-" + A;
        }
        bool ret_negative = (A[0] == '-') ^ (B[0] == '-');
        if (A[0] == '-') A.erase(A.begin());
        if (B[0] == '-') B.erase(B.begin());
        string l = "0", r = "1";
        int Alen = A.length();
        for (int i = 0; i < Alen - 1; ++i) {
            r += "0";
        }
        r += "1";
        auto division_by_two = [&](const string &s) -> string {
            if (s == "0" or s == "1") return "0";
            string ret = "";
            int idx = 0;
            int tmp = s[idx] - '0';
            while (tmp < 2) tmp = tmp * 10 + (s[++idx] - '0');
            while (int(s.size()) > idx) {
                ret += (tmp / 2) + '0';
                tmp = (tmp % 2) * 10 + s[++idx] - '0';
            }
            if (ret.length() == 0) return "0";
            return ret;
        };
        auto is_greater = [&](const string &s1, const string &s2) { //s1 < s2
            if (s1.length() < s2.length()) return true;
            else if (s1.length() > s2.length()) return false;
            else return (s1.compare(s2) < 0);
        };
        while (is_greater(addition(l, one), r)) {
            string mid = division_by_two(addition(l, r));
            if (is_greater(A, multiplication(mid, B))) {
                r = mid;
            }
            else l = mid;
        }
        ret = (!ret_negative or (ret_negative and (multiplication(B, l) == A))) ? l : r;
        if (ret_negative) ret = "-" + ret;
        return ret;
    }
}

void toPostfix(string &exp) {
    string ret = ""; stack<char> stk;
    for (const auto &e : exp) {
        if (e >= 'A' and e <= 'A' + 9) {
            ret += e;
        }
        else {
            if (e == '+' || e == '-') {
                while (!stk.empty() && stk.top() != '(') {
                    ret += stk.top();
                    stk.pop();
                }
                stk.push(e);
                continue;
            }
            else if (e == '*' || e == '/')
            {
                while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                    ret += stk.top();
                    stk.pop();
                }
                stk.push(e);
                continue;
            }
            else [[unlikely]] assert(0);
        }
    }
    while (!stk.empty()) {
        ret += stk.top();
        stk.pop();
    }
    exp = ret;
}
void eval(string &exp, vector<string> &num) {
    using namespace arithmetic;
    stack<string> stk;
    for (const auto &e : exp) {
        string tmp1 = "", tmp2 = "";
        if (e == '+') {
            tmp1 = stk.top();
            stk.pop();
            tmp2 = stk.top();
            stk.pop();
            stk.push(addition(tmp2, tmp1));
        }
        else if (e == '-') {
            tmp1 = stk.top();
            stk.pop();
            tmp2 = stk.top();
            stk.pop();
            stk.push(subtraction(tmp2, tmp1));
        }
        else if (e == '*') {
            tmp1 = stk.top();
            stk.pop();
            tmp2 = stk.top();
            stk.pop();
            stk.push(multiplication(tmp2, tmp1));
        }
        else if (e == '/') {
            tmp1 = stk.top();
            stk.pop();
            tmp2 = stk.top();
            stk.pop();
            stk.push(division(tmp2, tmp1));
        }
        else {
            stk.push(num[e - 'A']);
        }
    }
    cout << stk.top() << "\n";
}
string tmp, input, ret, num1, num2, expression;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<string> num, op, tmpnum;
    while (cin >> input) {
        static char alph = 'A';
        if (isdigit(input[0]) or (input.length() > 1 and input[0] == '-' and isdigit(input[1]))) {
            num.emplace_back(input);
            input = alph++;
        }
        else op.emplace_back(input);
        expression += input;
    }
    toPostfix(expression);
    eval(expression, num);
    return 0;
}