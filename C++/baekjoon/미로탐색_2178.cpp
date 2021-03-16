#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define X first
#define Y second

string maze[100];
int dist[100][100];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    FAST;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>maze[i];
    for(int i=0;i<n;i++) fill(dist[i], dist[i]+m, -1);
    queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0][0] = 1;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny] >= 0 || maze[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    cout<<dist[n-1][m-1];
}
