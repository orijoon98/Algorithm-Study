#include <bits/stdc++.h>
using namespace std;



const int MAX = 20;



int N;

int graph[MAX][MAX];

int road[MAX][MAX];

int result;



void floyd(void)

{

    for (int k = 0; k < N; k++)

        for (int i = 0; i < N; i++)

            for (int j = 0; j < N; j++)

                if (i == j || j == k || i == k)

                    continue;

    //플로이드 성립 X(최소 이동시간이 아니다)

                else if (graph[i][j] > graph[i][k] + graph[k][j])

                {

                    result = -1;

                    return;

                }

    //i->j로 가는 경로가 k를 거쳐가는 경우와 같다면

    //모든 경로를 최소의 도로로 커버해야하므로 k를 거쳐가는 도로를 선택한다

                else if (graph[i][j] == graph[i][k] + graph[k][j])

                    road[i][j] = false;

}



int main(void)

{

    cin >> N;



    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

            cin >> graph[i][j];



    memset(road, true, sizeof(road));

    floyd();



    //-1이면 불가능

    if (result != -1)

        for (int i = 0; i < N; i++)

            for (int j = 0; j < N; j++)

                if (road[i][j])

                    result += graph[i][j];



    if (result == -1)

        cout << -1 << endl;

    else

        //i->j, j->i 둘다 계산했으므로 반으로 나누어준다

        cout << result / 2 << endl;

    return 0;

}