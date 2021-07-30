#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int cost[501];
vector<int> v[501];
int realCost[501];
int degree[501];

void BFS()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
            q.push(i);

        realCost[i] = cost[i];
    }

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (int i = 0; i < v[curNode].size(); i++)
        {
            int nextNode = v[curNode][i];

            realCost[nextNode] = max(realCost[nextNode], realCost[curNode] + cost[nextNode]);

            if (--degree[nextNode] == 0)
                q.push(nextNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];

        while (1)
        {
            int temp;

            cin >> temp;

            if (temp == -1)
                break;
            else
            {
                degree[i]++;
                v[temp].push_back(i);
            }
        }
    }

    BFS();

    for (int i = 1; i <= N; i++)
        cout << realCost[i] << '\n';
}