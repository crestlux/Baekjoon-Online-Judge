#include <stdio.h>
#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
int dpi[1001], dpd[1001], v[1001];
int main() {
    const int MIN = -987654321;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    dpi[0] = dpd[N - 1] = 1;
    for (int i = 1; i < N; i++) {
        int maxlen = MIN;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) maxlen = max(maxlen, dpi[j] + 1);
        }
        dpi[i] = (maxlen == MIN) ? 1 : maxlen;
    }
    for (int i = N - 2; i >= 0; i--) {
        int maxlen = MIN;
        for (int j = N - 1; j > i; j--) {
            if (v[i] > v[j]) maxlen = max(maxlen, dpd[j] + 1);
        }
        dpd[i] = (maxlen == MIN) ? 1 : maxlen;
    }
    int ret = MIN;
    for (int i = 0; i < N; i++) {
        ret = max(ret, dpi[i] + dpd[i] - 1);
    }
    printf("%d\n", ret);
    return 0;
}