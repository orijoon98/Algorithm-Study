#include <bits/stdc++.h>
#define endl '\n'
#define MAX INT_MAX

using namespace std;

string str;
int zero, one;

void Input() {
	cin >> str;
}

void Solution() {
	// ���ӵ� 0�Ǽ�, 1�Ǽ� ���� �� �ּڰ� ���
	for (int i = 0; i < str.size() - 1; i++) {
		char cur = str[i];
		if (cur != str[i + 1]) {
			if (cur == '0') zero++;
			else one++;
		}
	}
	if (str[str.size() - 1] == '0') zero++;
	else one++;
	cout << min(zero, one) << endl;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}