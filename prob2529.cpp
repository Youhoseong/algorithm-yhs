using namespace std;	
#include <iostream>
#include <string>
string ary[9];
int N;
const long MAX = 100000000000;
long maxData = -MAX;
string maxdata;
long minData = MAX;
string mindata;

void compareInsert(int cnt, string printedInt) {
	//cout <<"string val " <<printedInt << endl;
	//cout << "cnt : " << cnt << endl;
	if (cnt == N) {
		maxData = max(maxData, stol(printedInt));
	
		if (maxData == stol(printedInt))
			maxdata = printedInt;

		minData = min(minData, stol(printedInt));
		if (minData == stol(printedInt))
			mindata = printedInt;

		/*cout << "maxdata Int: " << maxData << endl;
		cout << "mindata Int: " << minData << endl;

		cout << "maxdata: " << maxdata << endl;
		cout <<"mindata: " << mindata << endl;
		*/
		return;
	}

	if (ary[cnt] == "<") {
		int temp = printedInt[cnt] - '0';
	
		for (int i = 0; i < 10; i++) {
			int checkRedundant = 0;
			for (int j = 0; j < printedInt.length(); j++) {
				if (printedInt[j] - '0'== i) {
					checkRedundant = 1;
					break;
				}
			}

			if (temp < i && checkRedundant ==0)
				compareInsert(cnt + 1, printedInt + to_string(i));
			
		}
	}
	else if(ary[cnt] == ">"){
		int temp = printedInt[cnt] - '0';
	
		for (int i = 0; i < 10; i++) {
			int checkRedundant = 0;
			for (int j = 0; j < printedInt.length(); j++) {
				if (printedInt[j] - '0' == i) {
					checkRedundant = 1;
					break;
				}
			}

			if (temp > i && checkRedundant == 0)
				compareInsert(cnt + 1, printedInt + to_string(i));

		}
	}

}


int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> ary[i];


	compareInsert(0, "0");
	compareInsert(0, "1");
	compareInsert(0, "2");
	compareInsert(0, "3");
	compareInsert(0, "4");
	compareInsert(0, "5");
	compareInsert(0, "6");
	compareInsert(0, "7");
	compareInsert(0, "8");
	compareInsert(0, "9");

	cout << maxdata << endl;
	cout << mindata << endl;
}