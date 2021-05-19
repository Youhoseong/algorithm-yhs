#include <iostream>
#include <math.h>

using namespace std;
int N;
int dp[1001];

int A[1001];
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (A[j] > A[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }

    //for (int i = 1; i <= N; i++)
    //	cout << dp[i] << " ";
    cout << answer;
}