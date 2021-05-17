#include <iostream>
#include <math.h>

using namespace std;

int N;
int dp[1001][10];
int main()
{
    cin >> N;

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans = (ans + dp[N][i]) % 10007;
    }
    cout << ans;
}