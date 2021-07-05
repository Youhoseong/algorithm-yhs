#include <iostream>

using namespace std;



int main(){
    long long N;
    cin >> N;

    long long dp[1000001];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1] % 15746) + (dp[i-2] % 15746);
    }


    cout << dp[N] % 15746;

}

