#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
int ans;
priority_queue<int> pq;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		pq.push(-n);
	}
}

void Solution() {
	int cnt = 0;
	while (!pq.empty()) {
		if (cnt == N - 1) break;
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += -(a + b);
		pq.push(a + b);
		cnt++;
		//if (pq.size() == 1) break;
	}
	cout << ans << endl;
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

	return 0;
}