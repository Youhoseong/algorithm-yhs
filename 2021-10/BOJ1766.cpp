#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> v[32001];
int cntPreBuild[32001];

void bfs()
{

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= N; i++)
    {
        if (cntPreBuild[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curBuild = q.top();
        q.pop();
        cout << curBuild << " ";

        for (int i = 0; i < v[curBuild].size(); i++)
        {
            int nextBuild = v[curBuild][i];

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

    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        v[temp1].push_back(temp2);
        cntPreBuild[temp2]++;
    }

    bfs();
}