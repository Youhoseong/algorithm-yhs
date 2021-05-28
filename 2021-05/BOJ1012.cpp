

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int T;

int xdir[4] = { 0, 1, -1, 0 };
int ydir[4] = { 1, 0, 0, -1 };
bool visited[51][51];

int map[51][51];
void BFS(int row, int col, int M, int N) {
	queue<pair<int, int>> q;

	q.push({ row,col });
	visited[row][col] = true;

	while (!q.empty()) {
		int curRow = q.front().first;
		int curCol = q.front().second;
	//	cout << curRow << " " << curCol << endl;;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = curRow + xdir[i];
			int nextCol = curCol + ydir[i];

			if (0 > nextRow or nextRow > N - 1 or nextCol <0 or nextCol > M - 1)
				continue;

			if (visited[nextRow][nextCol] == true)
				continue;

		//	cout << nextRow << " " << nextCol << endl;;
			if (map[nextRow][nextCol] == 1) {
				q.push({ nextRow, nextCol });
				visited[nextRow][nextCol] = true;
			}
		}
	}

}




int main() {
	cin >> T;
	
	while (T--) {
		int cnt = 0;
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = false;
				map[i][j] = 0;
			}
		}
		vector<pair<int, int>> v;
		int M, N, K;
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int row, col;
			cin >> col >> row;
			map[row][col] = 1;
			v.push_back({ row, col });
		}

		for (int i = 0; i < K; i++) {
			int row = v[i].first;
			int col = v[i].second;

			if (visited[row][col] == false) {
				BFS(row,col, M, N);
				cnt++;
			}
		}


		cout << cnt << endl;
	}


}