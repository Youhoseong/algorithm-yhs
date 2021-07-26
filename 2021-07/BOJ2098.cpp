#include <iostream>
#include <string.h>
using namespace std;


int N;
int w[16][16];
int cost[16][1<<16];
const int IMPOSSIBLE = 1987654321;

// 시작점은 방문한 것.
int TSP(int current, int visited) {
	int& ret = cost[current][visited];

	// cost 이미 계산 완료.
	if (ret != -1)
		return ret;

	if (visited == (1 << N) - 1) {
		if (w[current][0] != 0)
			return w[current][0];
		// 갈수 없는 경로이므로 탐색 종료, 가장 큰 값을 부여해서 최소 경로에서 제외
		else
			return IMPOSSIBLE;
	}


	// 가장 큰 값으로 초기화( 최솟값 찾기위해)
	ret = IMPOSSIBLE;

	for (int i = 0; i < N; i++) {
		if ((visited & (1 << i)) || (w[current][i]) == 0) {
			continue;
		}

		ret = min(ret, w[current][i] + TSP(i, visited | (1 << i)));

	}
	return ret;

}


int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}

	//초기화
	memset(cost, -1, sizeof(cost));
	cout << TSP(0, 1) << '\n';



}