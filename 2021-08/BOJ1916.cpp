#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N;
int M;
vector<pair<int, int>> node[1001];

int minCost[1001];

void graphTraverse(int start)
{
    minCost[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({minCost[start], start});

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        if (minCost[curNode] < curCost)
            continue;

        for (int i = 0; i < node[curNode].size(); i++)
        {
            int nextNode = node[curNode][i].first;
            int nextCost = node[curNode][i].second + curCost;

            if (nextCost < minCost[nextNode])
            {
                minCost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

int main()
{

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int temp1, temp2, temp3;

        cin >> temp1 >> temp2 >> temp3;
        node[temp1].push_back({temp2, temp3});
    }

    for (int i = 1; i <= N; i++)
    {
        minCost[i] = 987654321;
    }

    int start, end;
    cin >> start >> end;

    graphTraverse(start);

    cout << minCost[end];
}
