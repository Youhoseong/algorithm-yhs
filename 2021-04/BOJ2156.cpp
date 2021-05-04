#include <iostream>

using namespace std;
int N;
int dp[10001];
int grapeGlass[10001];
int answer;
int main() {

    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        scanf("%d",&grapeGlass[i]);

    dp[1] = grapeGlass[1];
    dp[2] = grapeGlass[1] + grapeGlass[2];
    dp[3] = max(dp[2],max(grapeGlass[1] + grapeGlass[3], grapeGlass[2] + grapeGlass[3]));


    for(int i=4; i<=N; i++){
        dp[i] = max(dp[i-1],max(dp[i-3] + grapeGlass[i-1] + grapeGlass[i], dp[i-2] + grapeGlass[i]));

    }
    
    printf("%d",dp[N]);
}