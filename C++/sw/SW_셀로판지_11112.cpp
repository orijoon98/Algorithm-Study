#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int T, p, q, r, a, b, c, d;

//���� �߽��� ���簢�� �ȿ� �ִ��� Ȯ��
bool circleInSquare(int p, int q, int a, int b, int c, int d) {
	if (a <= p && p <= c && b <= q && q <= d) return true;
	return false;
}

void Solution() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> p >> q >> r;
		cin >> a >> b >> c >> d;
		int x = 987654321, X = 0; // x�� ���� �߽ɿ��� ���簢������ �ּҰŸ�, X�� �ִ�Ÿ�
		x = min(x, abs(p - a));
		x = min(x, abs(p - c));
		x = min(x, abs(q - b));
		x = min(x, abs(q - d)); // ���簢���� �������� �Ÿ��� �ּ�
		x *= x;
		X = max(X, (p - a) * (p - a) + (q - b) * (q - b));
		X = max(X, (p - a) * (p - a) + (q - d) * (q - d));
		X = max(X, (p - c) * (p - c) + (q - b) * (q - b));
		X = max(X, (p - c) * (p - c) + (q - d) * (q - d)); // �� ������������ �Ÿ� �� �ִ�
		if (circleInSquare(p, q, a, b, c, d)) {
			cout << "#" << i << " ";
			if (r * r <= x) cout << "N";
			else cout << "Y";
			if (r * r >= X) cout << "N";
			else cout << "Y";
			cout << endl;
		}
		else { // ���� �߽��� ���簢�� �ۿ� �ִٸ�
			cout << "#" << i << " ";
			cout << "Y"; // ���� ������ ���δ�
			if (r * r >= X) cout << "N";
			else cout << "Y";
			cout << endl;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}