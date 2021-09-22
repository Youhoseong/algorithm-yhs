#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MAX 501
using namespace std;

/*

 한 노드에서 상하좌우 탐색을 4번 수행했을 때, 'ㅗ' 를 제외한 모든 테트로미노 모형이 된다
 따라서 'ㅗ' 를 예외처리로 두고 나머지를 DFS 탐색을 통해 수행하면 모든 경우를 탐색할 수 있다

 - 전체 맵을 탐색 (n * m)
 - 각 노드별 DFS 탐색 (4^4)
 - 에외 경우 탐색 (4*4)

 시간복잡도 : O(500^2 * (4^4 + 4*4)) = O(68,000,000)

*/

int n,m,ans;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int exception_case[4][4][2] = {
        {{0,0},{0,-1},{0,1},{-1,0}},
        {{0,0},{-1,0},{1,0},{0,1}},
        {{0,0},{0,-1},{0,1},{1,0}},
        {{0,0},{-1,0},{1,0},{0,-1}}
};

void dfs(int x,int y,int cnt,int sum){
    // 테트로미노를 만든 경우
    if(cnt == 4){
        ans = max(ans,sum);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

        if(!visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx,ny,cnt+1,sum+map[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

// 'ㅗ' 의 경우 예외처리
// 4방향 x 정사각형 4개
void getExceptionCase(int x,int y){
    for(int i=0; i<4; i++){
        bool flag = true;
        int sum = 0;

        for(int j=0; j<4; j++){
            int nx = x + exception_case[i][j][0];
            int ny = y + exception_case[i][j][1];

            if(nx<0 || ny<0 || nx>=n || ny>=m){
                flag = false;
                break;
            }

            sum += map[nx][ny];
        }

        if(flag)
            ans = max(ans,sum);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = true;
            dfs(i,j,1,map[i][j]);
            visited[i][j] = false;

            // 'ㅗ' 의 경우 예외처리
            getExceptionCase(i,j);
        }
    }

    cout << ans << "\n";

    return 0;
}