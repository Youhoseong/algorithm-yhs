using namespace std;

#include <iostream>

int N;
int cost[11][11];
bool check[11] = { false, };
int recordCity[12] = { 0, };

int minCost = 100000000;
void dfs(int index) {
	if (index > N) {
		int tempCost = 0;
		recordCity[index ] = recordCity[1];

		
	//	for (int i = 1; i <= index; i++)
		//	cout << recordCity[i] << " ";

	//	cout << endl;
		

		for (int i = 1; i <= N ; i++) {
			tempCost += cost[recordCity[i]][recordCity[i + 1]];

		}
	//	cout << "tempCost:" << tempCost << endl;
	//	cout << "mincost :" << minCost << endl;
		minCost = min(minCost, tempCost);

	}


	for (int i = 1; i <= N; i++) {
		if ( !check[i] ) { // i번째 도시를 들리지 않았다면
			if (index > 1 && !cost[recordCity[index - 1]][i]) {
			  continue;
			}

			if (index == 4 && !cost[i][recordCity[1]]) {
			//	cout << "hi:" << i << endl;
				continue;
			}

			check[i] = true;
			//cout << "recordC: " << i << endl;
			recordCity[index] = i;
			dfs(index + 1);
			check[i] = false;

		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> cost[i][j];

	}

	dfs(1);

	cout << minCost << endl;
}