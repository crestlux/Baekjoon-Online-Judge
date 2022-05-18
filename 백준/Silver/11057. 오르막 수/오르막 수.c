#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
int dp[1002][10];
int main() {
    const int mod = 10007;
    int N, ret = 0, sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1; dp[2][i] = i + 1;
    }
    for (int i = 3; i < 1001; i++) {
        sum = 0;
        for (int j = 0; j < 10; j++) {
            sum = (sum % mod + dp[i - 1][j] % mod) % mod;
            dp[i][j] = sum;
        }
    }
    for (int i = 0; i < 10; i++) {
        ret += dp[N][i];
    }
    printf("%d\n", ret % mod);
    return 0;
}