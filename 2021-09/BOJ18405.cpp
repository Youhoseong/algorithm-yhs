#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N, K;
int cnt;
int sihum[200][200];
bool visited[200][200];
int rowDir[4] = {-1, 1, 0, 0};
int colDir[4] = {0, 0, 1, -1};

void bfs(int s)
{
    bool visited2[200][200];
    memset(visited2, false, sizeof(visited2));
    while (s--)
    {
        vector<pair<int, pair<int, int>>> v;
        queue<pair<int, int>> q;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (sihum[i][j] && !visited[i][j])
                {
                    v.push_back({sihum[i][j], make_pair(i, j)});
                    visited[i][j] = true;
                }
            }
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            //cout << "v:" << v[i].first << " " << v[i].second.first <<" " << v[i].second.second << endl;
            q.push({v[i].second.first, v[i].second.second});
            visited2[v[i].second.first][v[i].second.second] = true;
        }

        while (!q.empty())
        {
            int curRow = q.front().first;
            int curCol = q.front().second;

            //cout << "현재: "<<  curRow <<" "<< curCol << endl;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextRow = curRow + rowDir[i];
                int nextCol = curCol + colDir[i];

                if (0 > nextRow or nextRow > N - 1 or nextCol < 0 or nextCol > N - 1)
                {
                    continue;
                }

                if (visited2[nextRow][nextCol])
                {
                    continue;
                }
                else
                {
                    //cout << "미래: " <<nextRow << " " << nextCol << endl;
                    sihum[nextRow][nextCol] = sihum[curRow][curCol];
                    visited2[nextRow][nextCol] = true;
                }
            }
        }

        /*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << sihum[i][j] << " ";
			}
			cout << endl;
		}
		*/
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> sihum[i][j];
        }
    }

    int S, X, Y;
    cin >> S >> X >> Y;

    bfs(S);

    cout << sihum[X - 1][Y - 1] << endl;
}