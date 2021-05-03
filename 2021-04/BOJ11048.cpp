#include <iostream>


using namespace std;

int main() {
    int N, M;
    int candy[1001][1001];
    int dp[1001][1001];
    scanf("%d %d", &N, &M);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &candy[i][j]);
        }
    }

    dp[1][1] = candy[1][1];
    for(int i=2; i<=M; i++)
        dp[1][i] = candy[1][i] + dp[1][i-1];

    for(int i=2; i<=N; i++)
        dp[i][1] = candy[i][1] + dp[i-1][1];

    for(int i=2; i<=N; i++) {
        for(int j=2; j<=M; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + candy[i][j];
        }
    }   
/*    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
*/

    printf("%d", dp[N][M]);
}