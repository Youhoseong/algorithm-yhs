#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int N, apple, mov;
int map[101][101];

queue<pair<int, char>> turn;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    cin >> N;
    cin >> apple;

    for (int i = 0; i < apple; i++)
    {
        int temp1, temp2;

        cin >> temp1 >> temp2;
        map[temp1][temp2] = 1;
    }

    cin >> mov;

    for (int i = 0; i < mov; i++)
    {
        int temp1;
        char temp2;
        cin >> temp1 >> temp2;

        turn.push({temp1, temp2});
    }

    queue<pair<int, int>> snake;
    snake.push({1, 1});
    map[1][1] = 2;

    pair<int, int> cur = {1, 1};
    int curDir = 2;
    int curTime = 0;

    int xDir[4] = {-1, 0, 1, 0};
    int yDir[4] = {0, -1, 0, 1};

    while (1)
    {
        int nextRow = cur.first + yDir[curDir];
        int nextCol = cur.second + xDir[curDir];
        curTime++;

        if ((1 > nextRow or nextRow > N or 1 > nextCol or nextCol > N) || map[nextRow][nextCol] == 2)
        {
            break;
        }

        if (map[nextRow][nextCol] == 0)
        {
            pair<int, int> rear = snake.front();
            map[rear.first][rear.second] = 0;
            snake.pop();
        }
        snake.push({nextRow, nextCol});
        map[nextRow][nextCol] = 2;

        if (turn.size() && curTime == turn.front().first)
        {
            if (turn.front().second == 'D')
            {
                curDir = (curDir + 1) % 4;
            }
            else
            {
                curDir = (curDir + 3) % 4;
            }

            turn.pop();
        }
        cur = {nextRow, nextCol};
    }

    cout << curTime;

    return 0;
}