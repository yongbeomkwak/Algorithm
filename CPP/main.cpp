#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define null 0
#define endl "\n"
#define MAX 10
using namespace std;

//topological sorting
int inDegree[MAX];          // 진입 차수 의미
vector<int> node_info[MAX]; // 각 정점에 연결되어 있는 모든 노드 정보(핵심은 벡터의 배열을 사용하여함 , 한 지점에서 여러개로 갈 수 있으므로 )
int n;
void topologySort()
{
    int result[MAX]; // 위상정렬을 수행한 결과값 담는 배열
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0) //진입 차수가 없다는 뜻은(출발 지점 또는 그 전에는 연결되있지만 앞이 끊어지면 새로운 출발지점인 상태)
        {
            q.push(i); //해당 출발지점 넣어줌
        }
    }
    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드 방문해야함
    for (int i = 1; i <= n; i++)
    {
        // n개의 노드를 방문하기 전에 큐가 비면 사이클 발생
        if (q.empty())
        {
            printf("사이클이 발생했습니다.\n");
            return;
        }
        // 큐의 가장 앞의 원소를 빼서 result 배열에 넣어줌
        int x = q.front(); //출발지점 노드를 뺌
        q.pop();
        result[i] = x; // 결과 넣어줌 

        // 꺼낸 원소에 연결이 되어있는 모든 정점들을 확인하면서 간선제거
        for (int j = 0; j < node_info[x].size(); j++)
        {
            int y = node_info[x][j]; // 한 지점에서 여러개의 간선이 있을 수 있기 때문에 반복 

            // 진입차수가 0인 노드 큐에 삽입
            if (--inDegree[y] == 0) //지점을 끊었을 시 만약 간선이 존재하지 않으면 새로운 출발지점이 됨
            {
                q.push(y);
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << endl;
    }
}

int main()
{
    n = 7; // 노드 개수

    node_info[1].push_back(2); // 1번 노드 -> 2번 노드
    inDegree[2]++;     // 2번 노드의 진입차수 1 증가

    node_info[1].push_back(5);
    inDegree[5]++;

    node_info[2].push_back(3);
    inDegree[3]++;

    node_info[3].push_back(4);
    inDegree[4]++;

    node_info[4].push_back(6);
    inDegree[6]++;

    node_info[5].push_back(6);
    inDegree[6]++;

    node_info[6].push_back(7);
    inDegree[7]++;

    topologySort();
}