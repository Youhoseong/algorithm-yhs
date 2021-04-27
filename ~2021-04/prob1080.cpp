#include <iostream>
#include <vector>

using namespace std;

void flip(int a[][50], int x, int y, int N, int M){

    for(int i=x; i<x+3; i++){
        for(int j=y; j< y+3 ;j++){
            if(i>=0 && j>=0 && i<=N-1 && j<=M-1){
                a[i][j] = 1 - a[i][j];
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << a[i][j] << " ";

        cout << endl;
    }

}
bool checkequality(int a[][50], int b[][50], int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(a[i][j] != b[i][j])
                return false;

        }


    }

    return true;

}


int main() {
    int N, M;
    cin >> N >> M;
    int v[50][50];
    int wantTobe[50][50];
    for(int i=0; i<N ;i++){
        string temp;
        cin >> temp;
        for(int j=0; j<M; j++){
            v[i][j] = temp[j]-'0';        
        }
    }
    for(int i=0; i<N ;i++){
        string temp;
        cin >> temp;
        for(int j=0; j<M; j++)
            wantTobe[i][j] = temp[j]- '0';

    }

    int cnt=0;

    for(int i=0; i<N-2; i++) {
        for(int j=0; j<M-2; j++){
            if(v[i][j] != wantTobe[i][j]){
                flip(v, i, j, N, M);
                cnt++;
            }
        }

    }

    if(checkequality(v, wantTobe, N, M)){
        cout << cnt << '\n';

    }
    else 
        cout << -1 << '\n';
    
    return 0;
}