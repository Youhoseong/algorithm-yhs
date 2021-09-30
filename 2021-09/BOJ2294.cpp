#include <iostream>
#include <vector>

using namespace std;
int N, K;
vector<int> v;
int dp[100001];
int main()
{

    cin >> N >> K;
    for (int i = 1; i <= K; i++)
    {
        dp[i] = 123456789;
    }

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
        dp[temp] = 1;
    }

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i >= v[j])
            {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    if (dp[K] == 123456789)
    {
        cout << -1;
    }
    else
    {
        cout << dp[K];
    }
}