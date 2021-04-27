using namespace std;

#include <iostream>
#include <string>


int N;
int S;
int ary[20];
int countN = 0;
void permutation(int index, int sum) {

	sum += ary[index];

	if (index < 0)
		return;
		
	if (sum == S) {
		countN++;

	}

	permutation(index -1, sum - ary[index]);
	permutation(index -1, sum );
	
		
}


int main() {

	cin >> N;
	cin >> S;

	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}


	permutation(N-1, 0);
	

	cout << countN <<endl;
}