#include <bits/stdc++.h>
#define endl '\n'
#define MAX 21
#define SMAX 401
using namespace std;

int N, M, K;
pair<pair<int,int>, pair<int,int>> Map[MAX][MAX]; // 상어번호, 상어방향, 영역, 남은시간
vector<pair<pair<int,int>,pair<int,int>>> tmp; // 현재 상어의 번호, 방향, 위치
int dx[4] = {-1, 1, 0, 0}; // 위, 아래, 왼쪽, 오른쪽
int dy[4] = {0, 0, -1, 1}; // 위, 아래, 왼쪽, 오른쪽
int Sdir[SMAX][4][4]; // 상어의 방향 우선순위
bool Shark[SMAX]; // 남아있는 상어
bool Visit[MAX][MAX];
int ans; // 걸리는 시간

void Input(){
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>Map[i][j].first.first; // 상어 번호
            int SharkNum = Map[i][j].first.first;
            if(SharkNum != 0){
                Shark[SharkNum] = true; // 남아있는 상어 표시
                Map[i][j].second.first = SharkNum; // 영역 표시
                Map[i][j].second.second = K; // 남은 시간
                tmp.push_back({{SharkNum,0},{i,j}}); // 방향 지정을 위해 상어번호와 좌표 잠시 저장
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    for(int i=1;i<=M;i++){
        int dir; cin>>dir;
        for(int j=0;j<tmp.size();j++){
            if(tmp[j].first.first == i){
                Map[tmp[j].second.first][tmp[j].second.second].first.second = dir-1; // 상어 방향 지정
                tmp[j].first.second = dir-1;
                break;
            }
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int dir; cin>>dir;
                Sdir[i][j][k] = dir-1;
            }
        }
    }
}

void Move(){ // 남아있는 모든 상어 이동
    for(int sn=1;sn<=M;sn++){
        if(!Shark[sn]) continue; // 쫓겨난 상어라면 움직이지 않음
        int curNum = sn;
        int curX = tmp[sn-1].second.first;
        int curY = tmp[sn-1].second.second;
        int curDir = tmp[sn-1].first.second; // 현재 상어가 보고있는 방향
        bool moved = false;
        for(int i=0;i<4;i++){
            int nDir = Sdir[curNum][curDir][i];
            int nX = curX + dx[nDir];
            int nY = curY + dy[nDir];
            if(nX < 1 || nY < 1 || nX > N || nY > N) continue;
            if(Map[nX][nY].second.second == 0){ // 빈 영역이라면
                tmp[sn-1].first.first = sn;
                tmp[sn-1].first.second = nDir;
                tmp[sn-1].second.first = nX;
                tmp[sn-1].second.second = nY;
                moved = true;
                break;
            }
        }
        if(!moved){ // 빈 영역으로 움직이지 못했다면 자기 영역으로 이동
            for(int i=0;i<4;i++){
                int nDir = Sdir[curNum][curDir][i];
                int nX = curX + dx[nDir];
                int nY = curY + dy[nDir];
                if(nX < 1 || nY < 1 || nX > N || nY > N) continue;
                if(Map[nX][nY].second.first == curNum){ // 자기 영역이라면
                    tmp[sn-1].first.first = sn;
                    tmp[sn-1].first.second = nDir;
                    tmp[sn-1].second.first = nX;
                    tmp[sn-1].second.second = nY;
                    moved = true;
                    break;
                }
            }
        }
    }
    ans++;
}

void CheckShark(){ // 쫓겨난 상어 판별
    for(int i=0;i<MAX;i++) fill(Visit[i], Visit[i]+MAX, false);
    for(int i=0;i<M;i++){
        if(!Shark[i+1]) continue;
        if(Visit[tmp[i].second.first][tmp[i].second.second]) {
            Shark[i+1] = false;
//            cout<<i+1<<" dead"<<endl;
        }
        Visit[tmp[i].second.first][tmp[i].second.second] = true;
    }
}

void SetMap(){ // 맵 업데이트
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(Map[i][j].second.second > 0){
                Map[i][j].second.second--;
                if(Map[i][j].second.second == 0){
                    Map[i][j].second.first = 0;
                    Map[i][j].first.first = 0;
                    Map[i][j].first.second = 0;
                }
            }
        }
    }
    for(int i=0;i<M;i++){
        if(!Shark[i+1]) continue;
        int x = tmp[i].second.first;
        int y = tmp[i].second.second;
        Map[x][y].first.first = i+1;
        Map[x][y].first.second = tmp[i].first.second;
        Map[x][y].second.first = i+1;
        Map[x][y].second.second = K;
    }
}

bool Count(){
    int cnt = 0;
    for(int i=1;i<=M;i++){
        if(Shark[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}

void Print(){
    for(auto cur: tmp){
        cout<<cur.first.first<<": "<<cur.second.first<<","<<cur.second.second<<endl;
    }
}

void Solution(){
    for(int i=0;i<1000;i++){
        Move();
        CheckShark();
        SetMap();
        if(Count()){
            cout<<ans<<endl;
            return;
        }
    }
    cout<<-1<<endl;
//    for(int i=0;i<1000;i++){
//        Move();
//        CheckShark();
//        SetMap();
//        cout<<ans<<endl;
//        Print();
//        if(Count()){
//            return;
//        }
//    }
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
