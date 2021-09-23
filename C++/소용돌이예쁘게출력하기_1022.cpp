#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int MAP[50][5];
int r1, c1, r2, c2;

void Input() {
	cin >> r1 >> c1 >> r2 >> c2;
}

void Setting() {
	int x = r2 - r1;
	int y = c2 - c1;
	// r1, c1 ÀÌ 0, 0
	int i = 5000, j = 5000;
	int x1 = 5000 + r1; int y1 = 5000 + c1;
	int x2 = 5000 + r2; int y2 = 5000 + c2;
	int cur = 1;
	int cnt = 1;
	if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
		MAP[i-x1][j-y1] = cur;
	}
	cur++;
	while (true) {
		j++; // ¿À¸¥ÂÊÀ¸·Î ÇÑÄ­
		if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
			MAP[i - x1][j - y1] = cur;
		}
		cur++;
		while (i != 5000 - cnt) { // À§·Î Âß
			i--;
			if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
				MAP[i - x1][j - y1] = cur;
			}
			cur++;
		}
		while (j != 5000 - cnt) { // ¿ÞÂÊÀ¸·Î Âß
			j--;
			if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
				MAP[i - x1][j - y1] = cur;
			}
			cur++;
		}
		while (i != 5000 + cnt) { // ¾Æ·¡·Î Âß
			i++;
			if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
				MAP[i - x1][j - y1] = cur;
			}
			cur++;
		}
		while (j != 5000 + cnt) { // ¿À¸¥ÂÊÀ¸·Î Âß
			j++;
			if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
				MAP[i - x1][j - y1] = cur;
			}
			cur++;
		}
		cnt++;
		if (i == 10000 && j == 10000) break;
	}
}

void Solution() {
	int x1 = 0;
	int y1 = 0;
	int x2 = r2 - r1;
	int y2 = c2 - c1;

	int Length = 0;
	Length = max(Length, int(to_string(MAP[x1][y1]).size()));
	Length = max(Length, int(to_string(MAP[x1][y2]).size()));
	Length = max(Length, int(to_string(MAP[x2][y1]).size()));
	Length = max(Length, int(to_string(MAP[x2][y2]).size()));

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			int Space = Length - int(to_string(MAP[i][j]).size());
			while (Space--) cout << ' ';
			cout << MAP[i][j];
			cout << ' ';
		}
		cout << endl;
	}
}

void Solve() {
	Input();
	Setting();
	Solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();

	return 0;
}