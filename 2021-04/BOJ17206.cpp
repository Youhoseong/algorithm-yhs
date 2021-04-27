#include <iostream>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    
    for(int i=0; i<T; i++){
        int N;
        int answer = 0;
        scanf("%d", &N);
        for (int j=3; j<=N ; j+=3){
            answer += j;
        }
        
        for (int j=7; j<=N ; j+=7){
            answer += j;
        }
        
        for (int j=21 ; j<=N; j+=21)
            answer -= j;
        
        printf("%d\n",answer);
    }

    return 0;
}