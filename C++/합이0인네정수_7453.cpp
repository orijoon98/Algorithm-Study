#include <bits/stdc++.h>
#define endl '\n'
#define MAX 4001
#define ll long long
using namespace std;

int N;
int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];
vector<int> v1;
vector<int> v2;
ll ans;

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
}

void Solution(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            v1.push_back(A[i] + B[j]);
            v2.push_back(C[i] + D[j]);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for(int i=0;i<v1.size();i++){
        int low = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
        int high =upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
        
        ans += (high - low);
    }
    
    cout<<ans<<endl;
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
