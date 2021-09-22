#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int N;
int M;
int map[9][9];
bool visited[9][9];
int rowDir[4] = {-1,1, 0, 0};
int colDir[4] = {0, 0, 1, -1};
int tempmap[9][9];
int mx = -99;
vector<pair<int,int>> v;

void dfs(int i, int j) {
    stack<pair<int,int>> s;
    s.push({i, j});
    visited[i][j] =true;

    while(!s.empty()) {
        int curRow = s.top().first;
        int curCol = s.top().second;
        s.pop();

        for(int i=0; i<4; i++ ){
            int nextRow = curRow + rowDir[i];
            int nextCol = curCol + colDir[i];

            if(0 > nextRow or nextRow > N-1 or nextCol < 0 or nextCol > M-1) {
                continue;
            }

            if(!visited[nextRow][nextCol] && tempmap[nextRow][nextCol] == 0) {
                s.push({nextRow, nextCol});
                tempmap[nextRow][nextCol] = 2;
                visited[nextRow][nextCol] = true;
            }
        }
    }


}

void pickThrees(int cnt, int index) {
    if(cnt == 3) {
        memset(visited, false, sizeof(visited));

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++){
                tempmap[i][j] = map[i][j];
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) {
                if(map[i][j] == 2 && !visited[i][j]) {
                    dfs(i,j);
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++){
                if(tempmap[i][j] == 0) {
                    cnt++;
                }
            }
        }

        mx = max(mx, cnt);
        return;
    }else {
        if(index == v.size())
            return;

        int row = v[index].first;
        int col = v[index].second;
        map[row][col] = 1;
        pickThrees(cnt+1, index+1);

        map[row][col] = 0;
        pickThrees(cnt, index+1);

    }
}


int main() {
    cin >> N;
    cin >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) {
                v.push_back({i,j});
            }
        }
    }

    pickThrees(0, 0);

    cout << mx;


}