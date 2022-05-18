#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = N - i - 1; j > 0; j--) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < i * 2 - 1; j++) {
			cout << " ";
		}
		if (i != 0) cout << "*";
		cout << "\n";
	}
	return 0;
}