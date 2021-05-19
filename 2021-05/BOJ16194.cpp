#include <iostream>
#include <math.h>

using namespace std;

int N;
int card[1001];
int dp[1001];
int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> card[i];
        dp[i] = 10001;
    }

    dp[1] = card[1];
    dp[2] = min(dp[1] + card[1], card[2]);

    for (int i = 3; i <= N; i++)
    {

        for (int j = 1; j <= i - 1; j++)
        {
            dp[i] = min(dp[j] + card[i - j], dp[i]);
        }
        dp[i] = min(dp[i], card[i]);
    }
    cout << dp[N];
}