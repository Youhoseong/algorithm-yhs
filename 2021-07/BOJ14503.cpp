#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int r;
    int c;
    int d;
    int cnt;
};

int N, M;
int map[51][51];

void printMap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void bfs(int r, int c, int d)
{

    queue<node> q;
    q.push({r, c, d, 1});
    map[r][c] = 2;

    while (!q.empty())
    {
        //	printMap();
        int curRow = q.front().r;
        int curCol = q.front().c;
        int curDir = q.front().d;
        int curCnt = q.front().cnt;
        q.pop();

        int nextRow, nextCol, nextDir;

        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            if (curDir == 0)
            {
                nextDir = 3;
                nextRow = curRow;
                nextCol = curCol - 1;
            }
            else if (curDir == 1)
            {
                nextDir = 0;
                nextRow = curRow - 1;
                nextCol = curCol;
            }
            else if (curDir == 2)
            {
                nextDir = 1;
                nextRow = curRow;
                nextCol = curCol + 1;
            }
            else
            {
                nextDir = 2;
                nextRow = curRow + 1;
                nextCol = curCol;
            }
            if (map[nextRow][nextCol] == 0)
            {
                //cout << "이동:" << nextRow << " " << nextCol << " " << nextDir << endl;
                q.push({nextRow, nextCol, nextDir, curCnt + 1});
                map[nextRow][nextCol] = 2;
                flag = 1;
                break;
            }
            else
            {
                curDir = nextDir;
                //cout << "요깅" << endl;
            }
        }

        // 후진 가능 여부 체크
        if (flag == 0)
        {

            if (curDir == 0)
            {
                nextRow = curRow + 1;
                nextCol = curCol;
            }
            else if (curDir == 1)
            {
                nextRow = curRow;
                nextCol = curCol - 1;
            }
            else if (curDir == 2)
            {
                nextRow = curRow - 1;
                nextCol = curCol;
            }
            else if (curDir == 3)
            {
                nextRow = curRow;
                nextCol = curCol + 1;
            }

            if (map[nextRow][nextCol] == 2)
            {
                q.push({nextRow, nextCol, curDir, curCnt});
                //cout << "후진:" << nextRow << " " << nextCol << " " << curDir << endl;
            }
            else
            {
                cout << curCnt;
                break;
            }
        }
    }
}

int main()
{
    int r, c, d;

    cin >> N >> M;

    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    bfs(r, c, d);
}