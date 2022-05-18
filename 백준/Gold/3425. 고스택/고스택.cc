#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int endflag = 0;
bool chkError(stack<ll>& stack, const int& i) {
	if (stack.size() < i) {
		cout << "ERROR\n";
		while (!stack.empty()) {
			stack.pop();
		}
        endflag = 1;
		return true;
	}
	return false;
}

void clearStack(stack<ll>& stack) {
	while (!stack.empty()) {
		stack.pop();
	}
    endflag = 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<ll> st1; string s1 = ""; ll N, num;
	vector<string> vs; vector<ll>vi;
	while (1) {
		s1.clear(); 
		vs.clear(); vector<string>().swap(vs); 
		vi.clear(); vector<ll>().swap(vi);
		while (1) {
			cin.clear();
			if (endflag == 1) {
				cin.ignore();
				endflag = 0;
			}
			getline(cin, s1);
			vs.push_back(s1);
			if (s1 == "END") {
				break;
			}
			if (s1 == "QUIT") {
				return 0;
			}
		}
		cin >> N;
		vi.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> vi[i];
		}
		for (auto j = 0; j < vi.size(); j++) {
			while (!st1.empty()) {
				st1.pop();
			}
			st1.push(vi[j]);
			for (auto i = 0; i < vs.size(); i++) {
				if (vs[i].at(0) == 'N') {
					num = static_cast<ll>(stoi(vs[i].substr(4)));
					st1.push(num);
					continue;
				}
				if (vs[i] == "POP") {
					if (!st1.empty()) {
						st1.pop();
					}
                    else{
                        cout<<"ERROR\n";
                        endflag = 1;
                        break;
                    }
					continue;
				}
				if (vs[i] == "INV") {
					if (chkError(st1, 1)) break;
					ll temp;
					temp = -st1.top();
					st1.pop();
					st1.push(temp);
					continue;
				}
				if (vs[i] == "DUP") {
					if (chkError(st1, 1)) break;
					st1.push(st1.top());
					continue;
				}
				if (vs[i] == "SWP") {
					if (chkError(st1, 2)) break;
					ll temp1 = st1.top(), temp2;
					st1.pop();
					temp2 = st1.top();
					st1.pop();
					st1.push(temp1);
					st1.push(temp2);
					continue;
				}
				if (vs[i] == "ADD") {
					if (chkError(st1, 2)) break;
					ll temp1 = st1.top(), temp2, sum;
					st1.pop();
					temp2 = st1.top();
					sum = temp1 + temp2;
					if (abs(sum) > 1e9) {
						cout << "ERROR\n";
						clearStack(st1);
						break;
					}
					st1.pop();
					st1.push(sum);
					continue;
				}
				if (vs[i] == "SUB") {
					if (chkError(st1, 2)) break;
					ll temp1 = st1.top(), temp2, sub;
					st1.pop();
					temp2 = st1.top();
					sub = temp2 - temp1;
					if (abs(sub) > 1e9) {
						cout << "ERROR\n";
						clearStack(st1);
						break;
					}
					st1.pop();
					st1.push(sub);
					continue;
				}
				if (vs[i] == "MUL") {
					if (chkError(st1, 2)) break;
					ll temp1 = st1.top(), temp2, mul;
					st1.pop();
					temp2 = st1.top();
					mul = temp1 * temp2;
					if (abs(mul) > 1e9) {
						cout << "ERROR\n";
						clearStack(st1);
						break;
					}
					st1.pop();
					st1.push(mul);
					continue;
				}
				if (vs[i] == "DIV") {
					if (chkError(st1, 2)) break;
					ll temp1 = st1.top(), temp2;
					if (temp1 == 0) {
						cout << "ERROR\n";
						clearStack(st1);
						break;
					}
					st1.pop();
					temp2 = st1.top();
					st1.pop();
					st1.push(temp2 / temp1);
					continue;
				}
				if (vs[i] == "MOD") {
					if (chkError(st1, 2)) break;
					ll temp1 = st1.top(), temp2;
					st1.pop();
					if (temp1 == 0) {
						cout << "ERROR\n";
						clearStack(st1);
						break;
					}
					temp2 = st1.top();
					st1.pop();
					st1.push(temp2 % temp1);
					continue;
				}
				if (vs[i] == "END") {
					if (st1.size() != 1) {
						cout << "ERROR\n";
					}
					endflag = 1;
					break;
				}
			}
			if (st1.size() == 1) {
				cout << st1.top() << "\n";
				st1.pop();
			}
		}
		cout << "\n";
		cin.ignore();
	}
	return 0;
}