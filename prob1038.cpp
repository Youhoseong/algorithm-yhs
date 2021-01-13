#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int testcase;
	cin >> testcase;
	int i = 0;
	while (i < testcase) {
		int worker;
		cin >> worker;

		vector<pair<int, int>> grade;

		for (int i = 0; i < worker; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
	
			grade.push_back(make_pair(temp1, temp2));
		}

		sort(grade.begin(), grade.end());

		int cnt = 1;
		int temp = grade[0].second;
		for (int i = 1; i < worker; i++) {

			if (grade[i].second <= temp) {
				temp = grade[i].second;
				cnt++;

			}
			
		}

		cout << cnt << '\n';

		i++;
	}

	

}