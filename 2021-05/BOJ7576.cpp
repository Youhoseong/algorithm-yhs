#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomatoBox[1001][1001];

struct tomato
{
    int row;
    int col;
    int days;
};
int tomatoCount;
bool visited[1001][1001];
int dRow[4] = {1, 0, -1, 0};
int dCol[4] = {0, 1, 0, -1};
queue<tomato> q;

void BFS()
{
    int cnt = 0;
    while (!q.empty())
    {

        int curRow = q.front().row;
        int curCol = q.front().col;
        int curDays = q.front().days;
        //cout << curRow << " " << curCol <<" " <<curDays << endl;
        tomatoBox[curRow][curCol] = 1;
        cnt++;

        q.pop();

        /*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//cout << tomatoBox[i][j] << ' ';
				if (tomatoBox[i][j] == 1) {
					cnt++;
				}
			}
			//cout << '\n';
 		}
		*/
        //cout << cnt << " " << tomatoCount << '\n';
        if (cnt == tomatoCount)
        {
            cout << curDays;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextRow = curRow + dRow[i];
            int nextCol = curCol + dCol[i];
            //cout << nextRow << " " << nextCol << endl;
            if (nextRow < 0 or nextCol < 0 or nextRow > N - 1 or nextCol > M - 1)
                continue;

            if (visited[nextRow][nextCol])
                continue;

            if (tomatoBox[nextRow][nextCol] == 0)
            {

                q.push({nextRow, nextCol, curDays + 1});
            }
            visited[nextRow][nextCol] = true;
        }
    }

    cout << -1;
}

int main()
{
    cin >> M >> N;
    int startRow, startCol;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tomatoBox[i][j];
            if (tomatoBox[i][j] == 1)
            {
                tomatoCount++;

                q.push({i, j, 0});
                visited[i][j] = true;
            }
            else if (tomatoBox[i][j] == 0)
            {
                tomatoCount++;
            }
        }
    }

    BFS();
}