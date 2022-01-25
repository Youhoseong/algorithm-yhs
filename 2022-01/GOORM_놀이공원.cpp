#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include <stdlib.h>
#include<algorithm>


using namespace std;

int N, K, T;
int map[100][100];

int cntTrash(int row, int col) {
	int cnt = 0;
	
	
	if(row + K > N || col + K > N) {
		return 10001;
	}
	
	
	for(int i=row; i<row + K; i++) {
		for(int j=col ; j<col + K; j++) {
			if(map[i][j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}


int main() {
	cin >> T;
	
	
	while(T--) {
		cin >> N >> K;
		int minTrash = 10001;
		memset(map, 0, sizeof(map));
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				cin >> map[i][j];
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				
				int cnt =cntTrash(i, j);
				minTrash = min(minTrash, cnt);
			}
		}
		
		cout << minTrash << '\n';
		
		
	}
	
	
}
