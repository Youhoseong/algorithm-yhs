#include <iostream>
#include <vector>
using namespace std;

int N, K;
int dp[101][100001];
int map[101][2];
int main() {
	cin >> N >> K;
	

	for (int i = 1; i <= N; i++) {
		cin >> map[i][0] >> map[i][1];
	}


	//i는 현재의 최대 무게
	for (int i = 1; i <= N; i++) {
		int weight = map[i][0];
		int value = map[i][1];
		for (int j = 0; j <= K; j++) {
			if (j>=weight) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		}

	}

	cout << dp[N][K];

}