#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, M, ans;
int board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> melt;
deque<pair<int, int>> dq; // ġ�� �������� ���� �˱� ���� ��
bool vis[101][101];
bool flag = false, flag2 = false;


void Print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void DFS(int x, int y) {
	if (flag) return;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > M) {
			flag = true;
			return;
		}
		if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
		DFS(nx, ny);
	}
}

void Melt() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1) { // ġ�� �϶�
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) { // 4���� Ȯ��
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
					if (board[nx][ny] == 0) cnt++;
				}
				if (cnt >= 2) melt.push_back({ i,j });
			}
		}
	}
	for (auto cur : melt) {
		board[cur.first][cur.second] = 0; // ���δ�
	}
	ans++; // ���� Ƚ�� ����
	melt.clear();
	flag2 = true;
	// ��� ��Ҵ��� Ȯ��
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1) {
				flag2 = false;
				break;
			}
		}
	}
	// ��� �ȳ�Ҵٸ� ���� �κ� �������� �ٽ� üũ
	if (!flag2) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (board[i][j] == -1) {
					for (int x = 0; x < 101; x++) fill(vis[x], vis[x] + 101, 0);
					flag = false;
					DFS(i, j);
					if (flag) board[i][j] = 0; // �ȵ����ٸ� 0
				}
			}
		}
	}
}

void Cheese() {
	//�ѷ����� �κ� �ִ��� Ȯ��
	for (int i = dq.front().first; i <= dq.back().first; i++) {
		for (int j = dq.front().second; j <= dq.back().second; j++) {
			if (board[i][j] == 1) continue; // ġ��� ��ŵ
			for (int x = 0; x < 101; x++) fill(vis[x], vis[x] + 101, 0);
			flag = false;
			DFS(i, j);
			if (!flag) board[i][j] = -1;
		}
	}
	while (!flag2) {
		Melt();
	}
	cout << ans << endl;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) dq.push_back({ i,j });
		}
	}
}

void Solution() {
	Input();
	Cheese();
	//Print();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}