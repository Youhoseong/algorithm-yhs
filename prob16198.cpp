using namespace std;

#include <iostream>

int N;
int weight[11];
int maxEnergy = -1000000000;
int checkweight[11] = { false, };

void dfs(int index, int newN, int energy) {
	if (newN == 2 ) {

		maxEnergy = max(maxEnergy, energy);
		return;
	}
		
	for (int i =2; i < N; i++) { //index N에 대해서는 처리 x
		if (!checkweight[i]) {

			checkweight[i] = true;
			int indexLeft;
			int indexRight;

			for (int j = i; j >= 1; j--) {
				if (!checkweight[j]) {
					indexLeft = j;
					break;
				}
			}

			for (int j = i; j <= N; j++) {
				if (!checkweight[j]) {
					indexRight = j;
					break;
				}
			}

			
			
			dfs(index + 1, newN - 1, energy + (weight[indexLeft] * weight[indexRight]));
			checkweight[i] = false;
		}
	}
}



int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) 
		cin >> weight[i];
	
	dfs(2, N, 0);
	cout << maxEnergy << endl;

	return 0;
}