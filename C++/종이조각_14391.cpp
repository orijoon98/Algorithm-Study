#include <bits/stdc++.h>
#define endl '\n'
#define MAX 4
using namespace std;

int N, M, Answer;
int MAP[MAX][MAX];
int Select[16];
bool Visit[MAX][MAX];
vector<int> V;

void Input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            MAP[i][j] = str[j] - '0';
        }
    }
}

pair<int,int> Find_Point()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Visit[i][j] == false) return{ i, j };
        }
    }
    return{ -1, -1 };
}

int Find_Max_Size(int x, int y, char C)
{
    int R_Value = 0;
    if (C == 'G')
    {
        for (int i = y; i < M; i++)
        {
            if (Visit[x][i] == false) R_Value++;
            else break;
        }
    }
    else
    {
        for (int i = x; i < N; i++)
        {
            if (Visit[i][y] == false) R_Value++;
            else break;
        }
    }
    return R_Value;
}

void Make_Visit(int x, int y, int Size, char C, bool T)
{
    if (C == 'G')
    {
        for (int i = y; i < y + Size; i++)
        {
            Visit[x][i] = T;
        }
    }
    else
    {
        for (int i = x; i < x + Size; i++)
        {
            Visit[i][y] = T;
        }
    }
}

int Calculate(int x, int y, int Size, char C)
{
    int R_Value = 0;
    
    if (C == 'G')
    {
        for (int i = y; i < y + Size; i++)
        {
            R_Value = R_Value + MAP[x][i];
            R_Value = R_Value * 10;
        }
    }
    else
    {
        for (int i = x; i < x + Size; i++)
        {
            R_Value = R_Value + MAP[i][y];
            R_Value = R_Value * 10;
        }
    }
    R_Value = R_Value / 10;
    return R_Value;
}

void DFS(int Total)
{
    pair<int, int> Pos = Find_Point();
    int x = Pos.first;
    int y = Pos.second;
    
    if (x == -1 && y == -1)
    {
        if (Answer < Total) Answer = Total;
        return;
    }
 
    int Size = Find_Max_Size(x, y, 'G');
    for (int S = Size; S > 0; S--)
    {
        Make_Visit(x, y, S, 'G', true);
        int Temp = Calculate(x, y, S, 'G');
        DFS(Total + Temp);
        Make_Visit(x, y, S, 'G', false);
    }
    
    Size = Find_Max_Size(x, y, 'S');
    for (int S = Size; S > 0; S--)
    {
        Make_Visit(x, y, S, 'S', true);
        int Temp = Calculate(x, y, S, 'S');
        DFS(Total + Temp);
        Make_Visit(x, y, S, 'S', false);
    }
}

void Solution(){
    if (N == 1 && M == 1)
    {
        cout << MAP[0][0] << endl;
        return;
    }
    
    DFS(0);
    cout << Answer << endl;
}

void Solve(){
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
