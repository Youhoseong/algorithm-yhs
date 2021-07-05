#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int dp[100001];

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum + v[i] < v[i])
        {
            dp[i] = v[i];
            sum = v[i];
        }
        else
        {
            dp[i] = sum + v[i];
            sum += v[i];
        }
    }

    int maxValue = -99999;
    for (int i = 0; i < N; i++)
    {
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue;
}