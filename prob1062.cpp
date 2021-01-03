using namespace std;


#include <iostream>

int N, K;
int words[50];

int learn;
int answer;

int learn_alpa(int cnt, int start) {
	int answer=0;

	if (cnt == K) {
		for (int i = 0; i < N; i++) {
			if ((words[i] & learn) == words[i])
				answer++;
		}

		return answer;
	}

	for (int i = start; i < 26; i++) {
		if (!(learn & (1 << i))) {
			learn |= (1 << i);
			answer =max(answer, learn_alpa(cnt + 1, i+1));
			learn &= ~(1 << i);
		}
	}


	return answer;
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.length(); j++) 
			words[i] |= (1 << (temp[j] - 'a'));

	}




	learn |= (1 << ('a' - 'a'));
	learn |= (1 << ('n' - 'a'));
	learn |= (1 << ('t' - 'a'));
	learn |= (1 << ('i' - 'a'));
	learn |= (1 << ('c' - 'a'));


	if (K < 5 || K == 26) 
		cout << (K == 26 ? N : 0) << endl;
	
	else
		cout << learn_alpa(5,0) << endl;

	return 0;
}