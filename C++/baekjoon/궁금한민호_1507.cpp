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

    //�÷��̵� ���� X(�ּ� �̵��ð��� �ƴϴ�)

                else if (graph[i][j] > graph[i][k] + graph[k][j])

                {

                    result = -1;

                    return;

                }

    //i->j�� ���� ��ΰ� k�� ���İ��� ���� ���ٸ�

    //��� ��θ� �ּ��� ���η� Ŀ���ؾ��ϹǷ� k�� ���İ��� ���θ� �����Ѵ�

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



    //-1�̸� �Ұ���

    if (result != -1)

        for (int i = 0; i < N; i++)

            for (int j = 0; j < N; j++)

                if (road[i][j])

                    result += graph[i][j];



    if (result == -1)

        cout << -1 << endl;

    else

        //i->j, j->i �Ѵ� ��������Ƿ� ������ �������ش�

        cout << result / 2 << endl;

    return 0;

}