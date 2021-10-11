#include <iostream>
#include <vector>

#include <string>
using namespace std;

string X, Y;

int dp[3003][3003];

void printtt(int i, int j)
{
    if (dp[i][j] == 0)
    {
        return;
    }
    else
    {
        if (Y[i] == X[j])
        {
            printtt(i - 1, j - 1);
            cout << X[j];
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                printtt(i - 1, j);
            else
                printtt(i, j - 1);
        }
    }
}

int main()
{
    cin >> X >> Y;

    for (int i = 3; i <= Y.length(); i += 3)
    {
        for (int j = 3; j <= X.length(); j += 3)
        {
            if (Y.substr(i - 3, 3) == X.substr(j - 3, 3))
            {
                dp[i][j] = dp[i - 3][j - 3] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 3][j], dp[i][j - 3]);
            }
        }
    }

    cout << dp[Y.length()][X.length()] << '\n';

    //printtt(Y.length() - 1, X.length() - 1);
}
