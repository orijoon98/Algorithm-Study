#include <bits/stdc++.h>
#define endl '\n'
#define MAX 101
using namespace std;

int W, H;
char MAP[MAX][MAX];
int Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
pair<int, int> Start, End;
 
void Input()
{
    int Tmp = 0;
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'C')
            {
                if (Tmp == 0)
                {
                    Start.first = i;
                    Start.second = j;
                    Tmp++;
                }
                else
                {
                    End.first = i;
                    End.second = j;
                }
            }
            Visit[i][j] = 987654321;
        }
    }
}
 
int BFS(int a, int b)
{
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    for (int i = 0; i < 4; i++)
    {
        Q.push(make_pair(make_pair(a, b), make_pair(i, 0)));
    }
    Visit[a][b] = 0;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dir = Q.front().second.first;
        int Cnt = Q.front().second.second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nCnt = Cnt;
 
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (MAP[nx][ny] == '*') continue;
            if (Dir != i) nCnt = nCnt + 1;
            if (Visit[nx][ny] >= nCnt)
            {
                Visit[nx][ny] = nCnt;
                Q.push(make_pair(make_pair(nx, ny), make_pair(i, nCnt)));
            }
        }
    }
    return Visit[End.first][End.second];
}
 
void Solution()
{
    int R = BFS(Start.first, Start.second);
    cout << R << endl;
}
 
void Solve()
{
    Input();
    Solution();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
