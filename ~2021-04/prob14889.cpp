using namespace std;

#include <iostream>
#include <string>


int N;
int abilityArray[21][21];
int minData = 100000000;

int start_list[10];
int link_list[10];

bool check[21] = { false, };

void sumAbility(int cnt, int index) {
	if (cnt == N / 2) {
		int k=0;

		int startsum = 0;
		int linksum = 0;

		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				link_list[k] = i;
				k++;
			}

		}

		for (int j = 0; j < N / 2; j++) {
			for (int k = 1; k <= N; k++) {
				if (start_list[j] != k && check[k])
					startsum += abilityArray[start_list[j]][k];
				if (link_list[j] != k && !check[k])
					linksum += abilityArray[link_list[j]][k];
			}
		}

		minData = min(minData, abs(startsum - linksum));


	}
	
	for (int i = index+1; i <= N; i++) {
		if (!check[i]) {
			start_list[cnt] = i;
			check[i] = true;
			sumAbility(cnt + 1, i);
			check[i] = false;
		}

	}

}


int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) 
			cin >> abilityArray[i][j];
	}
	sumAbility(0, 0);
	cout << minData<< endl;

	return 0;
}