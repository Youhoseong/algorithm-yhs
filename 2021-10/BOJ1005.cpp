#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int N, K;
int obj;
long long buildCost[1001];
vector<int> v[1001];
int cntPreBuild[1001];
long long realCost[1001];
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

        if (curBuild == obj)
        {
            cout << realCost[curBuild] << endl;
            return;
        }

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

    cin >> T;

    while (T--)
    {
        cin >> N >> K;

        for (int i = 1; i <= N; i++)
        {
            cntPreBuild[i] = 0;
            realCost[i] = 0;
            v[i].clear();
            cin >> buildCost[i];
        }

        for (int i = 0; i < K; i++)
        {
            int temp1, temp2;

            cin >> temp1 >> temp2;

            v[temp1].push_back(temp2);
            cntPreBuild[temp2]++;
        }

        cin >> obj;
        bfs();
    }
}