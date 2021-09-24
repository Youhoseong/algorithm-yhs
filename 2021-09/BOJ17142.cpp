#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int N, M;
int map[50][50];
int tempmap[50][50];
int rowDir[4] = {-1, 1, 0, 0};
int colDir[4] = {0, 0, 1, -1};

vector<pair<int, int>> virus;
int answer = 10000000;

struct d
{
    int row;
    int col;
    int time;
};
int blankCount;
bool visited[50][50];

void bfs()
{
    queue<d> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 3 && !visited[i][j])
            {
                visited[i][j] = true;
                q.push({i, j, 0});
            }
        }
    }
    int bcount = 0;

    int maxTime = 0;
    while (!q.empty())
    {
        int curRow = q.front().row;
        int curCol = q.front().col;
        int curTime = q.front().time;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextRow = curRow + rowDir[i];
            int nextCol = curCol + colDir[i];

            if (0 > nextRow or nextRow > N - 1 or nextCol < 0 or nextCol > N - 1)
            {
                continue;
            }

            if (!visited[nextRow][nextCol])
            {
                if (map[nextRow][nextCol] == 0)
                {
                    q.push({nextRow, nextCol, curTime + 1});
                    maxTime = curTime + 1;
                    bcount++;
                }
                else if (map[nextRow][nextCol] == 2)
                {
                    q.push({nextRow, nextCol, curTime + 1});
                }

                visited[nextRow][nextCol] = true;
            }
        }
    }

    if (blankCount == bcount)
    {
        answer = min(answer, maxTime);
    }
}

void pickVirusActivate(int cnt, int index)
{
    if (cnt == M)
    {
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                tempmap[i][j] = map[i][j];
            }
        }

        bfs();
    }
    else
    {

        if (index == virus.size())
        {
            return;
        }
        else
        {
            map[virus[index].first][virus[index].second] = 3; // activate virus is 3
            pickVirusActivate(cnt + 1, index + 1);

            map[virus[index].first][virus[index].second] = 2; // unactivate virus is 2
            pickVirusActivate(cnt, index + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                virus.push_back({i, j});
            }
            else if (map[i][j] == 0)
            {
                blankCount++;
            }
        }
    }

    pickVirusActivate(0, 0);

    if (answer == 10000000)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}