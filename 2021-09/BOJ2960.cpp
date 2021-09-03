#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;


int N,K;
bool ary[1001];



int main(){
    cin >> N >> K;
    int cnt =0;
    for(int i=2; i<=N; i++) {
        if(ary[i]) {
            continue;
        }

        for(int j=i; j<=N; j+= i){
            if(!ary[j]) {
                ary[j] = true;
                cnt++;


                if (cnt == K) {
                    cout << j << endl;

                    return 0;
                }
            }

        }

    }



}

