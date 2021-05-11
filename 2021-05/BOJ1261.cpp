#include <iostream>
#include <deque>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int xdir[4] = { 1,0,0, -1 };
int ydir[4] = { 0,1,-1, 0 };

int N, M;
int maze[101][101];
bool visit[101][101];

void zero_one_bfs();

int main() {
    scanf("%d %d", &M, &N);
        
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    zero_one_bfs();


}
typedef struct nodeInfo {
    int x;
    int y;
    int sum;
}Node;

void zero_one_bfs() {

    deque<Node> dq;

    visit[1][1] = true;
    dq.push_back({ 1,1,0 });

    while (!dq.empty()) {
        int cur_x = dq.front().x;
        int cur_y = dq.front().y;
        int sum = dq.front().sum;
        dq.pop_front();

        if (cur_x == N && cur_y == M) {
            printf("%d", sum);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int now_x = cur_x + xdir[i];
            int now_y = cur_y + ydir[i];
            

            if (now_x < 1 || now_y <1 || now_x > N || now_y > M) 
                continue;
            
             

            if (!visit[now_x][now_y]) {

                if (maze[now_x][now_y]) {
                    dq.push_back({ now_x, now_y, sum + maze[now_x][now_y] });
                }
                else {
                    dq.push_front({ now_x, now_y, sum });
                }
                visit[now_x][now_y] = true;

            }
        }

    }


}