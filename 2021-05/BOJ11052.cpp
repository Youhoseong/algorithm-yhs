#include <iostream>


using namespace std;

int N;
int P[1002];
int dp[1002];
int main() {
    scanf("%d", &N);

    for(int i=1; i<=N; i++) {
        scanf("%d", &P[i]);
    }

    dp[1] = P[1];
    dp[2] = max(P[1]*2, P[2]);

    for(int i=1; i<=N; i++) {
        int maxvalue = max(P[i], P[1] * i);
        for(int j=1 ; j<=i/2; j++){
            maxvalue = max(maxvalue, dp[j]+dp[i-j]);
        }
        dp[i] = maxvalue;
    }

    printf("%d",dp[N]);
}