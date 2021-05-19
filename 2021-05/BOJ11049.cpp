#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int dp[501][501];
int main()
{
    cin >> N;
    int p[501];

    for (int i = 0; i < N; i++)
    {
        int row, col;
        cin >> row >> col;
        p[i] = row;
        p[i + 1] = col;
    }

    //	for (int i = 0; i <= N; i++)
    //		cout << p[i] << " ";

    //	cout << endl;

    for (int l = 2; l <= N; l++)
    {
        for (int i = 1; i <= N - l + 1; i++)
        {
            int j = i + l - 1;
            cout << "i: " << i << " j: " << j << endl;
            dp[i][j] = 2147483647;
            for (int k = i; k <= j - 1; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }
    /*
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 6; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/

    cout << dp[1][N];
}