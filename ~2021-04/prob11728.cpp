#include <iostream>
#include <vector>

using namespace std; 

const int MAX = 1000001;

int N, M;
int A[MAX], B[MAX], ans[MAX];

void merge() {

    int A_index=0;
    int B_index=0;
    int ans_index=0;

    while(1){
        if(A_index >= N || B_index >= M)
            break;

        if(A[A_index] <= B[B_index]){
            ans[ans_index] = A[A_index];
            A_index++;
            ans_index++;

        }
        else  {
            ans[ans_index] = B[B_index];
            B_index++;
            ans_index++;
        }


    }

    while(A_index < N){
        ans[ans_index] = A[A_index];
        ans_index++;
        A_index++;

    }
    while(B_index < M){
        ans[ans_index] = B[B_index];
        ans_index++;
        B_index++;
        
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for(int i=0 ; i<N; i++)
        cin >> A[i];

    for(int i=0 ; i<M; i++)
        cin >> B[i];  

    merge();

    for(int i=0; i<N+M; i++)
        cout << ans[i] <<" ";
    

}