#include <bits/stdc++.h>
using namespace std;
void draw(char(&g)[2188][2188], int x, int y, int size) {
    if (size == 3) {
        for (int i = y; i < y + size; i++) {
            for (int j = x; j < x + size; j++) {
                g[i][j] = '*';
            }
        }
        g[y + 1][x + 1] = ' ';
        return;
    }
    draw(g, x, y, size / 3);
    draw(g, x + size / 3, y, size / 3);
    draw(g, x + ((size / 3) << 1), y, size / 3);
    draw(g, x, y + size / 3, size / 3);
    draw(g, x + ((size / 3) << 1), y + size / 3, size / 3);
    draw(g, x, y + ((size / 3) << 1), size / 3);
    draw(g, x + (size / 3), y + ((size / 3) << 1), size / 3);
    draw(g, x + ((size / 3) << 1), y + ((size / 3) << 1), size / 3);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    char g[2188][2188]; int N;
    fill(&g[0][0], &g[2187][2188], ' ');
    cin >> N;
    draw(g, 0, 0, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << g[i][j];
        }
        cout << "\n";
    }
    return 0;
}