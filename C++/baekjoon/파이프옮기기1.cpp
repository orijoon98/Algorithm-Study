#include <bits/stdc++.h>
#define endl '\n'
#define MAX 17
using namespace std;

int N;
int board[MAX][MAX];
int dp[MAX][MAX][3]; // 1,1 ����  a,b ���� ����� c �϶� ������ ����� ��

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
}

void Solve() {
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 3; j <= N; j++) {
			if (board[i][j] == 1) continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2]; // ���� ����� ��
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2]; // ���� ����� ��
			if (board[i - 1][j] == 1 || board[i][j - 1] == 1) continue;
			dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]; // �밢�� ����� ��
		}
	}
}

void Solution() {
	Input();
	Solve();
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solution();
}