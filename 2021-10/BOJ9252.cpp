#include <iostream>
#include <vector>

#include <string>
using namespace std;



string X, Y;

int dp[1001][1001];



void printtt(int i, int j) {
	if (dp[i][j] == 0) {
		return;
	}
	else {
		if (Y[i] == X[j]) {
			printtt(i - 1, j - 1);
			cout << X[j];
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1])
				printtt(i - 1, j);
			else
				printtt(i, j - 1);
		}
	}
}


int main() {
	cin >> X >> Y;

	X = "0" + X;
	Y = "0" + Y;

	for (int i = 1; i <= Y.length()-1; i++) {
		for (int j = 1; j <= X.length()-1; j++) {
			if (X[j] == Y[i]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
		}
	}

	cout << dp[Y.length()-1][X.length()-1] << '\n';

	printtt(Y.length() - 1, X.length() - 1);


}
