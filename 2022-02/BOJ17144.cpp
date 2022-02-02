#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int map[50][50];

int row, col, T;
int rowDir[4] = {-1, 1, 0 ,0};
int colDir[4] = {0, 0, -1, 1};
int spreadMap[50][50];
int copyMap[50][50];

int ccDir[4] = {3, 0, 2, 1};
int cDir[4] = {3, 1, 2, 0};
// 3 1 2 0

vector<pair<int,int>> cleanMachine;

void copy() {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col ; j++){
            copyMap[i][j] = map[i][j];
        }

    }
}

void spread() {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++){

            if(map[i][j] == -1 or map[i][j] == 0) {
                continue;
            }
            int cnt = 0;

            for(int k=0; k<4; k++){
                int nextRow = i + rowDir[k];
                int nextCol = j + colDir[k];

                if(map[nextRow][nextCol] == -1) {
                    continue;
                }

                if(nextRow < 0 or nextRow > row -1 or nextCol < 0 or nextCol > col -1 ) {
                    continue;
                }
                cnt++;
                spreadMap[nextRow][nextCol] += (int) map[i][j] / 5;
            }

            spreadMap[i][j] = spreadMap[i][j] - ((int)map[i][j]/ 5) * cnt;

        }
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<col ; j++){
           map[i][j] += spreadMap[i][j];
        }

    }

    memset(spreadMap, 0, sizeof(spreadMap));

}


void rotate(int startRow, int startCol, int dir[]) {
    pair<int,int> cleanLoc = {startRow, startCol};
    startCol++;
    map[startRow][startCol] = 0;
    //cout << "row, col :" << startRow << " " << startCol << '\n';
    for(int i=0; i<4; i++) {

        while(1) {

            int nextRow = startRow + rowDir[dir[i]];
            int nextCol = startCol + colDir[dir[i]];
            //cout << "row, col :" << nextRow << " " << nextCol << '\n';
            if(nextRow < 0 or nextRow > row -1 or nextCol < 0 or nextCol > col -1 ) {
                break;
            }

            if(nextRow == cleanLoc.first and nextCol == cleanLoc.second) {
                break;
            }

            map[nextRow][nextCol] = copyMap[startRow][startCol];
            startRow = nextRow;
            startCol = nextCol;
        }
    }
    //cout << '\n';


}

int calculate() {
    int cnt = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col ; j++){
            if(map[i][j] != -1) {
                cnt += map[i][j];
            }
        }

    }

    return cnt;
}


void printAll() {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col ; j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}


int main() {

    cin >> row >> col >> T;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col ; j++){
            cin >> map[i][j];

            if(map[i][j] == -1) {
                cleanMachine.push_back({i, j});
            }
        }
    }


    while(T--) {
        spread();
        copy();
        rotate(cleanMachine[0].first, cleanMachine[0].second, ccDir);
        rotate(cleanMachine[1].first, cleanMachine[1].second, cDir);
      //  printAll();
    }

    int result = calculate();

    cout << result;





}