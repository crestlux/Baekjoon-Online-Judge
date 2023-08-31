#include <bits/stdc++.h>
using namespace std;
constexpr __float128 pi = 3.1415926535897932384626433832795028841971693993751058209749445923Q;
constexpr __float128 pi2 = 6.2831853071795864769252867665590057683943387987502116419498891846Q;
constexpr __float128 EPS = 0.0000000000000000000000000001Q;
int a, b, c;
__float128 sint(__float128 x) {
    if (-pi <= x && x <= pi) {
        __float128 n = 1, val = 0, s = x, denom = 1, nu = x, sign = 1;
        while (__builtin_fabsf128(s - val) > EPS) {
            val = s;
            n += 2;
            nu *= x * x;
            denom *= n * (n - 1);
            sign *= -1;
            s += nu / denom * sign;
        }
        return s;
    }
    else if (x > pi) {
        while (x > pi)  x -= pi2;
        return sint(x);
    }
    else {
        while (x < -pi) x += pi2;
        return sint(x);
    }
}
__float128 f(__float128 x) {
    return a * x + b * sint(x) - c;
}
double bisection(__float128 l, __float128 h) {
    __float128 m, ret;
    do {
        m = (l + h) / __float128(2);
        ret = f(m);
        if (__builtin_fabsf128(ret) < EPS) break;
        else if (ret < 0) l = m;
        else h = m;
    } while ((h - l) > EPS);
    return __int128_t(m * (__float128)(1e6) + 0.5) / (__float128)(1e6);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed; cout.precision(6);
    cin >> a >> b >> c;
    auto ret = bisection(c / a - 5, c / a + 5);
    cout << ret << "\n";
    return 0;
}