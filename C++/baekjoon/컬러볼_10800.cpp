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
	sort(v.begin(), v.end(), cmp); // ũ�� ���� �������� ����
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		int idx = i;

		// ���� �Ȱ��� ũ�Ⱑ ������ Ż��(�� ���� ������ �߱� ������ ������ ����ȴ�.)
		while (idx < vs && v[i].Size == v[idx].Size) ++idx;

		// �ڽŰ� ���� ũ��鿡 ���� ���� �����Ѵ�.
		for (int j = i; j < idx; j++) {
			ans[v[j].Index] = total - sum[v[j].Color];
		}

		// �ڽŰ� ���� ũ��鿡 ���� Size�� ��(total)
		// �׸��� �ڽŰ� ���� ���� ���� Size�� ��(sum[])
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