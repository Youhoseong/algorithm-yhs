#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;

int beforePrize[501];

bool graph[501][501];
int cntPreBuild[501];

vector<int> answer;
void bfs()
{

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (cntPreBuild[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curBuild = q.front();
        q.pop();
        answer.push_back(curBuild);

        for (int i = 1; i <= N; i++)
        {

            if (graph[curBuild][i])
            {
                int nextBuild = i;

                if (--cntPreBuild[nextBuild] == 0)
                {
                    q.push(nextBuild);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        answer.clear();
        memset(graph, false, sizeof(graph));
        for (int i = 1; i <= N; i++)
        {
            cin >> beforePrize[i];

            cntPreBuild[i] = 0;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                graph[beforePrize[i]][beforePrize[j]] = true;
                cntPreBuild[beforePrize[j]]++;
            }
        }

        cin >> M;

        for (int i = 0; i < M; i++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;

            if (graph[temp2][temp1])
            {
                graph[temp2][temp1] = false;
                graph[temp1][temp2] = true;
                cntPreBuild[temp1]--;
                cntPreBuild[temp2]++;
            }
            else
            {
                graph[temp2][temp1] = true;
                graph[temp1][temp2] = false;
                cntPreBuild[temp1]++;
                cntPreBuild[temp2]--;
            }
        }

        bfs();

        if (answer.size() != N)
        {
            cout << "IMPOSSIBLE" << '\n';
        }
        else
        {
            for (int i = 0; i < answer.size(); i++)
            {
                cout << answer[i] << " ";
            }

            cout << '\n';
        }
    }
}