using namespace std;

#include <iostream>
int k;
int S[12];
int tempS[6];
bool checkS[12] = { false, };
void dfs(int cnt, int index) {
	if (cnt == 6) {

		for (int i = 0; i < 6; i++)
			cout << tempS[i] <<" " ;

		cout << endl;
		return;
	}

	for (int i = index; i < k; i++) {
		if (!checkS[i]) {
			checkS[i] = true;
			tempS[cnt] = S[i];
			dfs(cnt + 1, index+1);
			checkS[i] = false;
		}
	}
}


int main() {

	while (1) {
		cin >> k;

		if (k == 0)
			break;

		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}

		dfs(0,0);
		cout << endl;


	}




	return 0;
}