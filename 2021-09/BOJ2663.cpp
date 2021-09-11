#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[25][25];

int rowDir[4] = {-1, 0, 1, 0};
int colDir[4] = {0, -1, 0, 1};
vector<int> answer;

struct info
{
    int row;
    int col;
};

bool visited[25][25];
void bfs(int row, int col)
{
    queue<info> q;
    q.push({row, col});
    visited[row][col] = true;
    int curCnt = 0;
    while (!q.empty())
    {
        int curRow = q.front().row;
        int curCol = q.front().col;

        q.pop();
        curCnt++;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = curRow + rowDir[i];
            int nextCol = curCol + colDir[i];

            if (nextRow < 0 or nextRow > N - 1 or nextCol < 0 or nextCol > N - 1)
            {
                continue;
            }

            if (map[nextRow][nextCol] && !visited[nextRow][nextCol])
            {

                q.push({nextRow, nextCol});
                visited[nextRow][nextCol] = true;
            }
        }
    }

    answer.push_back(curCnt);
}

int main()
{
    int cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j])
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}