#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < (i << 1) + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < ((N - i - 1) << 1) - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}