#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int N;
int noDoor1, noDoor2;
vector<int> v;
int orderNum;
int dp[21][21][21];

int solve(int index, int open1, int open2)
{
    if (index == orderNum)
    {
        return 0;
    }

    int result = dp[index][open1][open2];

    if (result != -1)
    {
        return result;
    }
    else
    {

        int target = v[index];
        dp[index][open1][open2] =
            min(abs(open1 - target) + solve(index + 1, target, open2), abs(open2 - target) + solve(index + 1, open1, target));

        return dp[index][open1][open2];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> noDoor1 >> noDoor2;

    cin >> orderNum;

    for (int i = 0; i < orderNum; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, noDoor1, noDoor2);

    return 0;
}