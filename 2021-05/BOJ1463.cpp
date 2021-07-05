
#include <iostream>
using namespace std;
int N;
int dp[1000001];
int main(){
    cin >> N;
    dp[2]=1;
    dp[3]=1;

    for(int i=4; i<=N; i++) {
        dp[i] = 2147483647;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        dp[i] = min(dp[i-1]+1, dp[i]);

    }
    cout << dp[N];

}
