#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int M, N;
bool map[1001][1001];
int dp[1001][1001];

int dirRow[3] = {-1, -1, 0};
int dirCol[3] = {-1, 0, -1};
int answer = 0;
void solve()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (map[i][j])
            {
                dp[i][j] = 10000;
                for (int k = 0; k < 3; k++)
                {
                    int nextRow = i + dirRow[k];
                    int nextCol = j + dirCol[k];

                    if (0 > nextRow or M <= nextRow or 0 > nextCol or N <= nextCol)
                    {
                        if (map[i][j])
                            dp[i][j] = 1;
                        else
                            dp[i][j] = 0;
                        break;
                    }
                    else
                    {
                        if (map[nextRow][nextCol])
                        {
                            dp[i][j] = min(dp[i][j], dp[nextRow][nextCol] + 1);
                        }
                        else
                        {
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
            else
            {
                dp[i][j] = 0;
            }
            answer = max(answer, dp[i][j]);
        }
    }
}

int main()
{

    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {

            if (temp[j] == '1')
            {
                map[i][j] = true;
            }
        }
    }

    solve();

    cout << answer * answer;
}
