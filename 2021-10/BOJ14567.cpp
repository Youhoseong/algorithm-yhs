#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int buildCost[10001];
vector<int> v[10001];
int cntPreBuild[10001];
int realCost[10001];
void bfs()
{

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (cntPreBuild[i] == 0)
        {
            q.push(i);
        }
        realCost[i] = buildCost[i];
    }

    while (!q.empty())
    {
        int curBuild = q.front();
        q.pop();

        for (int i = 0; i < v[curBuild].size(); i++)
        {
            int nextBuild = v[curBuild][i];

            realCost[nextBuild] = max(realCost[nextBuild], realCost[curBuild] + buildCost[nextBuild]);

            if (--cntPreBuild[nextBuild] == 0)
            {
                q.push(nextBuild);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        buildCost[i] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        v[temp1].push_back(temp2);
        cntPreBuild[temp2]++;
    }

    bfs();

    for (int i = 1; i <= N; i++)
    {
        cout << realCost[i] << " ";
    }
}