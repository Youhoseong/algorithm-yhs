#include <iostream>

using namespace std;


int map[2200][2200];
int result[3];

bool check(int startRow, int startCol, int size) {

    int temp = map[startRow][startCol];

    for(int i=startRow; i<startRow + size; i++){
        for(int j=startCol ; j<startCol+size ; j++){
            if(temp != map[i][j])
                return false;
        }

    }

    return true;
}
void divide(int startRow, int startCol, int size){

    if(check(startRow, startCol, size) == true) {
        result[map[startRow][startCol]]++;
    }
    else {
        int num = (size / 3) ;
        for(int i=0; i<3 ; i++){
            for(int j=0; j<3; j++){
                 divide(startRow + (num * i), startCol + (num * j), num);
            }
        }
       
    }


}

int main() {
    int N;
    cin >> N;

    for(int i=0 ; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            temp++;
            map[i][j] = temp;
        }
    }

    divide(0, 0, N);

    cout << result[0] << '\n';
    cout << result[1] << '\n';
    cout << result[2] << '\n';

    return 0;
}