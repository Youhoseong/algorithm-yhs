#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;



int N;
int cnt;
int board[15];
int isPut(int start) {
    for(int i=0 ; i<start; i++) {
        if(board[start] == board[i] or (start-i) == abs(board[start] - board[i])) {
            return 0;
        }
    }

    return 1;
}

void N_Queen(int start){

    if(start == N) {
        cnt++;
        return;
    }

    for(int i=0 ; i<N; i++) {
        board[start] = i;

        if(isPut(start)) {
            N_Queen(start+1);
        }
    }



}


int main(){
    cin >> N;
    N_Queen(0);
    cout << cnt;
}

