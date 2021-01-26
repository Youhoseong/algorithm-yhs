#include <iostream>

using namespace std;

int N;

int lengthofS(int n) {
	if (n == 0) {
		return 3;
	}
	else {

		return (lengthofS(n - 1) + n + 3 + lengthofS(n - 1));
	}

}

void makeS(int k, int n) {

	if (k == 0) {
		if (n == 1)
			cout << "m";
		else
			cout << "o";
	}
	else {
		int previous = lengthofS(k - 1);
		int middle = k + 3;
		if (n > previous && n <= previous +  middle) {
			//cout << "2번째 파트" << endl;
			if (n == previous + 1)
				cout << "m";
			else
				cout << "o";

		}
		else if(n <= previous){
			//cout << "1번째 파트" << endl;
			makeS(k - 1, n);
		}
		else {
			//cout << "3번째 파트" << endl;
			makeS(k - 1, n-(previous + middle));
		}

	}
}

int main() {
	cin >> N;

	int len;
	int k;
	for (int i = 0; i < N; i++) {
		len = lengthofS(i);
		if (len >= N) {
			k = i;
			break;
		}
	}
	//cout << k << endl;
	makeS(k, N);

	
	
 }