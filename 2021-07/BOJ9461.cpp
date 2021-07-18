#include <iostream>

using namespace std;

int T;
int main()
{
    long long dp[101];

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        cout << dp[N] << '\n';
    }
}