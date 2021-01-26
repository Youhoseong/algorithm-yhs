#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string ary_temp[64];
int ary[64][64];
vector<string> v;
bool check(int x, int y, int size) {

	int temp = ary[x][y];

	for(int i = x ;  i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (ary[i][j] != temp) {
				return false;
			}
		}

	}

	return true;
}



void divide(int x, int y, int size) {
	if (check(x, y, size)) { 
		v.push_back(to_string(ary[x][y]));
		return;
	}
	else {
		int unit = size / 2;
		v.push_back("(");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				divide(x + (unit * i) , y + (unit * j), unit);
			
			}
		}
		v.push_back(")");
	}

}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> ary_temp[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ary[i][j] = ary_temp[i][j] - '0';

	}

	divide(0, 0, N);


	for (int i = 0; i < v.size(); i++)
		cout << v[i];

 }