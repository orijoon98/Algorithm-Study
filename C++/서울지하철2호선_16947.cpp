#include <bits/stdc++.h>
#define endl '\n'
#define MAX 3030
using namespace std;

int N;
bool Visit[MAX];
bool Cycle;
bool CycleNode[MAX]; // 사이클이면 true
vector<int> Node[MAX];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		Node[a].push_back(b);
		Node[b].push_back(a);
	}
}

void FindCycle(int Cur, int Start, int cnt) {
	if (Cur == Start && cnt >= 2) {
		Cycle = true;
		return;
	}
	Visit[Cur] = true;
	for (int i = 0; i < Node[Cur].size(); i++) {
		int Next = Node[Cur][i];
		if (Visit[Next] == false) {
			FindCycle(Next, Start, cnt + 1);
		}
		else {
			if (Next == Start && cnt >= 2) {
				FindCycle(Next, Start, cnt);
			}
		}
		if (Cycle == true) return;
	}
}

int BFS(int a) {
	fill(Visit, Visit + MAX, false);
	queue<pair<int, int>> q;
	q.push({ a,0 });
	Visit[a] = true;
	while (!q.empty()) {
		int Cur = q.front().first;
		int Cnt = q.front().second;
		q.pop();
		if (CycleNode[Cur] == true) return Cnt;
		for (int i = 0; i < Node[Cur].size(); i++) {
			int Next = Node[Cur][i];
			if (Visit[Next] == false) {
				Visit[Next] = true;
				q.push({ Next, Cnt + 1 });
			}
		}
	}
}

void Solution() {
	for (int i = 1; i <= N; i++) {
		fill(Visit, Visit + MAX, false);
		Cycle = false;
		FindCycle(i, i, 0);
		if (Cycle == true) {
			CycleNode[i] = true;
		}
	}
	vector<int> Answer;
	for (int i = 1; i <= N; i++) {
		if (CycleNode[i] == true) {
			Answer.push_back(0);
			continue;
		}
		Answer.push_back(BFS(i));
	}
	for (int i = 0; i < Answer.size(); i++) {
		cout << Answer[i] << ' ';
	}
	cout << endl;
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