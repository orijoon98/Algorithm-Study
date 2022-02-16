#include <bits/stdc++.h>
using namespace std;

string str1, str2;

int lcs[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	str1 = '0' + a;
	str2 = '0' + b;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}

			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else {
				if (lcs[i - 1][j] > lcs[i][j - 1])
					lcs[i][j] = lcs[i - 1][j];
				else
					lcs[i][j] = lcs[i][j - 1];
			}
		}
	}

	cout << lcs[len1 - 1][len2 - 1] << '\n';

	int i = len1 - 1;
	int j = len2 - 1;
	stack<int> st; // �Ųٷ� ���� stack�� �̿�

	while (lcs[i][j] != 0)
	{
		// ��� ����
		// cout << " i :: " << i << " j :: " << j << endl;

		// ���̺��� ���� �ѹ����̶��
		// �������� �̵�
		if (lcs[i][j] == lcs[i][j - 1])
			j--;

		// �������� �̵�
		else if (lcs[i][j] == lcs[i - 1][j])
			i--;

		// ���� ���� ��� �ٸ� �ѹ����̶�� �밢�� �������� �̵�
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])
		{
			st.push(i);
			i--;
			j--;
		}
	}

	while (!st.empty())
	{
		cout << str1[st.top()];
		st.pop();
	}

}