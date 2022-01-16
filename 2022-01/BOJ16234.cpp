#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, L, R;

int map[50][50];

int xdir[4] = {-1, 1, 0, 0};
int ydir[4] = {0, 0, 1, -1};

bool visited[50][50];
bool isMoved;

void moveCountry(queue<pair<int, int>> record, int value)
{

    while (!record.empty())
    {
        int curRow = record.front().first;
        int curCol = record.front().second;
        record.pop();

        map[curRow][curCol] = value;
    }
}

void bfs(int row, int col)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> record;

    int sum = 0;

    q.push({row, col});
    record.push({row, col});

    visited[row][col] = true;

    while (!q.empty())
    {
        int curRow = q.front().first;
        int curCol = q.front().second;
        sum += map[curRow][curCol];

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextRow = curRow + xdir[i];
            int nextCol = curCol + ydir[i];

            if (0 > nextRow || nextRow > N - 1 || 0 > nextCol || nextCol > N - 1)
            {
                continue;
            }

            if (visited[nextRow][nextCol])
            {
                continue;
            }

            int diff = abs(map[curRow][curCol] - map[nextRow][nextCol]);

            if (L <= diff && diff <= R)
            {
                isMoved = true;
                visited[nextRow][nextCol] = true;

                q.push({nextRow, nextCol});
                record.push({nextRow, nextCol});
            }
        }
    }

    if (record.size() >= 2)
    {
        moveCountry(record, sum / record.size());
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    int answer = 0;
    while (1)
    {
        isMoved = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    bfs(i, j);
                }
            }
        }

        if (isMoved)
        {
            answer++;
        }
        else
        {
            cout << answer << '\n';
            break;
        }
    }

    return 0;
}