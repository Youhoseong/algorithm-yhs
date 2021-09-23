#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int N, M;
char map[50][50];

int rowDir[4] = {-1, 1, 0, 0};
int colDir[4] = {0, 0, 1, -1};

struct secret
{
    int row;
    int col;
    int time;
};

bool visited[50][50];
int answer;

void bfs(int row, int col)
{
    queue<secret> q;
    q.push({row, col, 0});
    visited[row][col] = true;

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

            if (0 > nextRow or nextRow > N - 1 or 0 > nextCol or nextCol > M - 1)
            {
                continue;
            }

            if (map[nextRow][nextCol] == 'L' && !visited[nextRow][nextCol])
            {
                visited[nextRow][nextCol] = true;

                answer = max(answer, curTime + 1);
                //cout << nextRow << " " << nextCol << " " << answer << endl;
                q.push({nextRow, nextCol, curTime + 1});
            }
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
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.length(); j++)
        {
            map[i][j] = temp[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 'L')
            {
                memset(visited, false, sizeof(visited));
                bfs(i, j);
            }
        }
    }

    cout << answer;
}