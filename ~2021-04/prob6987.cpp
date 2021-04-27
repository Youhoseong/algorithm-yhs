using namespace std;

#include <iostream>

int WDL[4][6][3];

int answer[4];
int result[6][3] = { 0, };
int team1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int team2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
void makeWDL(int cnt ) {

	if (cnt == 15) {
		for (int k = 0; k < 4; k++) {
			if (answer[k] == 1)
				continue;

			bool flag = true;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					if (result[i][j] != WDL[k][i][j]) {
						flag = false; //flag가 false면, 일치하지 않는 경우의 수
						break;
					}

				}

				if (!flag)
					break;



			}

			if (flag)
				answer[k] = 1;

		}



		return;
	}


	int t1 = team1[cnt];
	int t2 = team2[cnt];

	result[t1][0]++; // t1 win
	result[t2][2]++; // t2 lose
	makeWDL(cnt + 1);
	result[t1][0]--; // t1 win
	result[t2][2]--; // t2 lose


	result[t1][1]++; // t1 draw
	result[t2][1]++; // t2 draw
	makeWDL(cnt + 1);
	result[t1][1]--; // t1 draw
	result[t2][1]--; // t2 draw

	result[t1][2]++; // t1 lose
	result[t2][0]++; // t2 win
	makeWDL(cnt + 1);
	result[t1][2]--; // t1 lose
	result[t2][0]--; // t2 win

}




int main() {
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++)
				cin >> WDL[k][i][j];
		}
	}


	makeWDL(0);

	for (int i = 0; i < 4; i++)
		cout << answer[i] << " ";

	
}