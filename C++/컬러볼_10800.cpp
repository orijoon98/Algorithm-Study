#include <bits/stdc++.h>
#define endl '\n'
#define MAX 200002
using namespace std;

struct info {
	int Color, Size, Index;
};
int N;
int ans[MAX], sum[MAX], total;
vector<info> v;

bool cmp(const info& a, const info& b) {
	return a.Size < b.Size;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, s; cin >> c >> s;
		v.push_back({ c,s,i });
	}
}

void Solution() {
	sort(v.begin(), v.end(), cmp); // 크기 기준 오름차순 정렬
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		int idx = i;

		// 나와 똑같은 크기가 나오면 탈출(그 전은 정렬을 했기 때문에 작음이 보장된다.)
		while (idx < vs && v[i].Size == v[idx].Size) ++idx;

		// 자신과 같은 크기들에 대한 답을 저장한다.
		for (int j = i; j < idx; j++) {
			ans[v[j].Index] = total - sum[v[j].Color];
		}

		// 자신과 같은 크기들에 대한 Size의 합(total)
		// 그리고 자신과 같은 색깔에 대한 Size의 합(sum[])
		for (int j = i; j < idx; j++) {
			total += v[j].Size;
			sum[v[j].Color] += v[j].Size;
		}

		i = idx - 1;
	}
	for (int i = 0; i < N; i++) cout << ans[i] << endl;
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