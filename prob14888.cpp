#include <iostream>

using namespace std;

const int MAX = 1000000;
int maxData = -MAX;
int minData = MAX;
int data_[12];
int operator_[4];
int N;

void search(int plus, int minus, int multiply, int divide, int cnt, int sum) {

	if (cnt == N) {
		maxData = max(sum, maxData);
		minData = min(sum, minData);
	}
	if (plus > 0)
		search(plus - 1, minus, multiply, divide, cnt + 1, sum + data_[cnt]);
	if (minus > 0)
		search(plus, minus-1, multiply, divide, cnt + 1, sum - data_[cnt]);
	if (multiply > 0)
		search(plus, minus, multiply-1, divide, cnt + 1, sum * data_[cnt]);
	if (divide > 0)
		search(plus, minus, multiply, divide-1, cnt + 1, sum / data_[cnt]);

}


int main() {
	int sum = 0; 
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> data_[i];

	for (int i = 0; i < 4; i++)
		cin >> operator_[i];


	search(operator_[0], operator_[1], operator_[2], operator_[3], 1, data_[0]);

	cout << maxData << endl;
	cout << minData << endl;

}