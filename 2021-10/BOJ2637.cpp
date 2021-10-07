#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;

int cntPreBuild[101];
int part[101][101];
int dp[101][101];

vector<int> answer;

void bfs()
{

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (cntPreBuild[i] == 0)
        {
            q.push(i);
            dp[i][i] = 1;
        }
    }

    while (!q.empty())
    {
        int curBuild = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {

            // i를 만드는데 curBuild가 필요하다면,
            if (part[i][curBuild] > 0)
            {
                int nextBuild = i;
                for (int j = 1; j <= N; j++)
                {
                    dp[nextBuild][j] += dp[curBuild][j] * part[nextBuild][curBuild];
                }

                if (--cntPreBuild[i] == 0)
                {
                    q.push(i);
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

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;

        part[temp1][temp2] = temp3;
        cntPreBuild[temp1]++;
    }

    bfs();

    for (int i = 1; i <= N; i++)
    {
        if (dp[N][i] > 0)
        {
            cout << i << " " << dp[N][i] << '\n';
        }
    }
}