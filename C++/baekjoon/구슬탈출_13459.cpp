#include <bits/stdc++.h>
#define endl '\n'
#define MAX 11
using namespace std;

int N, M;
char board[MAX][MAX];
bool finish;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
pair<int, int> red;
pair<int, int> blue;


void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				red = { j,i };
				board[i][j] = '.';
			}
			if (board[i][j] == 'B') {
				blue = { j,i };
				board[i][j] = '.';
			}
		}
	}
}

void Track(int n) {
	if (n > 10) return;
	int rx = red.first;
	int ry = red.second;
	int bx = blue.first;
	int by = blue.second;
	for (int i = 0; i < 4; i++) {
		bool R = false, B = false;
		int nrx = rx, nry = ry;
		int nbx = bx, nby = by;
		while (1) {
			if (board[nry + dy[i]][nrx + dx[i]] == '.') {
				nry += dy[i];
				nrx += dx[i];
			}
			else if (board[nry + dy[i]][nrx + dx[i]] == 'O') {
				R = true;
				nry += dy[i];
				nrx += dx[i];
				break;
			}
			else if (board[nry + dy[i]][nrx + dx[i]] == '#') break;
		}
		while (1) {
			if (board[nby + dy[i]][nbx + dx[i]] == '.') {
				nby += dy[i];
				nbx += dx[i];
			}
			else if (board[nby + dy[i]][nbx + dx[i]] == 'O') {
				B = true;
				nby += dy[i];
				nbx += dx[i];
				break;
			}
			else if (board[nby + dy[i]][nbx + dx[i]] == '#') break;
		}
		if (B) continue; // �Ķ����� �� ���
		if (R) { // �������� �� ���
			finish = true;
			return;
		}
		if (nrx == nbx && nry == nby) { // �������� �Ķ����� ������ ���
			if (i == 0) {
				if (ry > by) nry += 1; //�������� �ؿ� �־��� ���
				else nby += 1;
			}
			else if (i == 1) {
				if (rx > bx) nbx -= 1; //�Ķ����� �� ���ʿ��� ������ ���
				else nrx -= 1;
			}
			else if (i == 2) {
				if (ry > by) nby -= 1; //�Ķ����� �� ������ ����
				else nry -= 1;
			}
			else if (i == 3) {
				if (rx > bx) nrx += 1; //�������� �� �����ʿ��� ����
				else nbx += 1;
			}
		}
		red.first = nrx;
		red.second = nry;
		blue.first = nbx;
		blue.second = nby;
		Track(n + 1);
		red.first = rx;
		red.second = ry;
		blue.first = bx;
		blue.second = by;
	}
}

void Solution() {
	Track(1);
	if (finish) cout << 1 << endl;
	else cout << 0 << endl;
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