#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int w,h;
int map[50][50];
bool visited[50][50];

int rowDir[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int colDir[8] = {0, 0, 1, -1, -1, 1, -1, 1 };

void bfs(int row, int col) {
    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = true;
    while(!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for(int i=0; i<8;i++) {
            int nextRow = curRow + rowDir[i];
            int nextCol = curCol + colDir[i];

            if(nextRow < 0 or nextRow > h-1 or nextCol < 0 or nextCol > w-1) {
                continue;
            }

            if(!visited[nextRow][nextCol] && map[nextRow][nextCol] == 1) {
                visited[nextRow][nextCol] = true;
                q.push({nextRow, nextCol});
            }
        }

    }



}



int main() {
    while(1) {
        cin >> w >> h;

        memset(visited, false, sizeof(visited));
        if(w==0 and h==0) {
            break;
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w ; j++) {
                cin >> map[i][j];
            }

        }
        int answer =0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w ; j++) {
                if(!visited[i][j] && map[i][j] == 1) {
                    bfs(i,j);
                    answer++;
                }
            }

        }

        cout << answer << endl;



    }


}