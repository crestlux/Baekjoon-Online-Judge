#include <bits/stdc++.h>

using namespace std;

int N, M, arr[100001];

int findNum(const int *arr, const int &len, const int &chk) {
	int start = 0, end = len - 1, mid;
		while (end >= start) {
		mid = (start + end) / 2;
		if (arr[mid] == chk) {
			return 1;
		}
		else if (arr[mid] > chk) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int chk;
		cin >> chk;
		cout << findNum(arr, N, chk) << "\n";
	}

	return 0;
}
