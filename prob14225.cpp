using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

int N;
int _data[20];
vector<int> subsetSum;

void dfs(int cnt, int sum) {
	if (cnt == N) {
		subsetSum.push_back(sum);
		return;
	}

	dfs(cnt + 1, sum + _data[cnt]);
	dfs(cnt + 1, sum);
}

int main() {
	cin >> N;
	int minvalue=0;
	bool flag = false;

	for (int i = 0; i < N; i++)
		cin >> _data[i];

	dfs(0,  0);

	sort(subsetSum.begin(), subsetSum.end());

	if (subsetSum[0] == 0)
		subsetSum.erase(subsetSum.begin());

	subsetSum.erase(unique(subsetSum.begin(), subsetSum.end()), subsetSum.end());



	for (int i = 1; i < subsetSum.back() ; i++) {
		
		if (i != subsetSum[i-1]) { 
			minvalue = i;
			break;
		}
	}
	if (minvalue == 0)
		minvalue = subsetSum.back() + 1;

	cout << minvalue;
}

