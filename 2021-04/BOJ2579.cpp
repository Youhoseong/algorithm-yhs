
#include <iostream>

using namespace std;
int N;
int score[301];
int dp[301];

int main() {

    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        scanf("%d",&score[i]);
    }

    dp[1] = score[1];
    dp[2] = score[1] +score[2];
    dp[3] = max(score[1]+score[3], score[2]+score[3]);

    printf("%d %d %d\n",dp[1],dp[2],dp[3]);

    for(int i= 4; i<=N; i++){
        dp[i] = max(dp[i-3]+ score[i-1]+score[i], dp[i-2]+score[i]);
        printf("dp %d: %d\n",i,dp[i]);
    }

    
    printf("%d",dp[N]);
    
}