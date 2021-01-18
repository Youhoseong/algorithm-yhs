#include <iostream>

using namespace std;

int N;
char map[2200][2200];

void init() {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            map[i][j]= ' ';
    }

}

void printStar() {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << map[i][j];

        cout << '\n';
    }

}

void insertStar(int mapsize, int x, int y) {
    if(mapsize==1)
        map[x][y]='*';
    else {
        int unit = mapsize/3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i ==1 && j==1)
                    continue;
                insertStar(unit, x + unit * i, y + unit * j);
            }

        }

    }
}

int main() {
  
    cin >> N;
    
    init();
    insertStar(N, 0, 0);

    printStar();

    return 0;
}