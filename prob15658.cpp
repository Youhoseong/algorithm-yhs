using namespace std;

#include <iostream>

int N;
int _data[11];
int operatornumber[4];
const int MAX = 1000000000 + 1;
int maxresult= -MAX;
int minresult = MAX;
void dfs(int plus , int minus, int multi, int divide, int result, int cnt) {

	if (cnt == N) {
		
		maxresult = max(maxresult, result);
		minresult = min(minresult, result);
		return;
	}


	if (plus > 0) 
		dfs(plus - 1, minus, multi, divide, result + _data[cnt], cnt + 1);
	if(minus >0)
		dfs(plus, minus-1, multi, divide, result - _data[cnt], cnt + 1);
	if(multi >0)
		dfs(plus, minus, multi-1, divide, result * _data[cnt], cnt + 1);
	if(divide >0)
		dfs(plus, minus, multi, divide-1, result / _data[cnt], cnt + 1);

}





int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> _data[i];

	for (int i = 0; i < 4; i++) 
		cin >> operatornumber[i];


	dfs(operatornumber[0], operatornumber[1], operatornumber[2], operatornumber[3], _data[0], 1);
	cout << maxresult << endl;
	cout << minresult << endl;

	return 0;
}