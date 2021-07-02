#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
int graph[101][101];
int rowDir[4] = {-1, 0, 0, 1};
int colDir[4] = {0, 1, -1, 0};

struct Miro
{
    int row;
    int col;
    int move;
};

bool visited[101][101];
void bfs()
{
    queue<Miro> q;
    q.push({0, 0, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        int curRow = q.front().row;
        int curCol = q.front().col;
        int curMove = q.front().move;

        q.pop();

        if (curRow == N - 1 and curCol == M - 1)
        {
            cout << curMove;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextRow = curRow + rowDir[i];
            int nextCol = curCol + colDir[i];

            if (nextRow < 0 or nextRow > N - 1 or nextCol < 0 or nextCol > M - 1)
                continue;

            if (visited[nextRow][nextCol])
                continue;

            if (!graph[nextRow][nextCol])
                continue;

            q.push({nextRow, nextCol, curMove + 1});
            visited[nextRow][nextCol] = true;
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = temp[j] - '0';
        }
    }

    bfs();
}