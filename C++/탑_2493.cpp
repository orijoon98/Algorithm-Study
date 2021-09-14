#include <bits/stdc++.h>
#define endl '\n'
#define MAX 500050
using namespace std;

int N;
vector<pair<int,int>> Tower;
stack<pair<int,int>> s;
int ans[MAX];

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        int a; cin>>a;
        Tower.push_back({a,i});
    }
}

void Solution(){
    s.push({Tower[N-1].first, N});
    for(int i=N-1;i>=1;i--){
        if(!s.empty() && s.top().first < Tower[i-1].first){
            while(!s.empty() && s.top().first < Tower[i-1].first){
                ans[s.top().second] = i;
                s.pop();
            }
            s.push({Tower[i-1].first,i});
        }
        else{
            s.push({Tower[i-1].first,i});
        }
    }
    for(int i=1;i<=N;i++){
        cout<<ans[i]<<' ';
    }
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
