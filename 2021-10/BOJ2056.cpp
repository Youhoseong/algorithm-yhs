#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
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

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> buildCost[i];

        int T;
        cin >> T;

        for (int j = 0; j < T; j++)
        {
            int temp;
            cin >> temp;

            v[temp].push_back(i);
            cntPreBuild[i]++;
        }
    }

    bfs();
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, realCost[i]);
    }
    cout << ans;
}