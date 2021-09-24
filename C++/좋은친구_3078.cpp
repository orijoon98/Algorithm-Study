#include <bits/stdc++.h>
#define endl '\n'
#define MAX 21
#define ll long long
using namespace std;

int N, K;
ll ans;
vector<ll> Arr[MAX]; // 길이가 인덱스인 사람들의 등수

void Input() {
	cin >> N >> K;
	for (ll i = 0; i < N; i++) {
		string str; cin >> str;
		Arr[str.size()].push_back(i);
	}
}

void Solution() {
	for (int i = 1; i <= 20; i++) {
		sort(Arr[i].begin(), Arr[i].end());
		// 이진탐색으로 개수 찾기
		for (int left = 0; left < Arr[i].size(); left++) {
			ll cur = Arr[i][left];
			ll right = upper_bound(Arr[i].begin(), Arr[i].end(), cur + K) - Arr[i].begin();
			if (left < right) {
				ans += (right - left - 1);
			}
		}
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