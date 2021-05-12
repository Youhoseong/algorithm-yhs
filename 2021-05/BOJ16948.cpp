#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N;
int r1, c1, r2, c2;
bool visit[201][201];

int rowDir[6] = {-2, -2, 0, 0,  2, 2};
int colDir[6] = {-1, 1, -2, 2, -1, 1};
int minvalue = 99999;
struct node {
    int row;
    int col;
    int count;
};


void BFS() {
    queue<node> q;

    q.push({ r1, c1, 0 });
    visit[r1][c1] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int row_cur = cur.row;
        int col_cur = cur.col;
        int count = cur.count;

        if (row_cur == r2 and col_cur == c2) {
            minvalue = min(minvalue, count);
        }


        for (int i = 0; i < 6; i++) {
            int row_now = row_cur + rowDir[i];
            int col_now = col_cur + colDir[i];
            if (row_now < 0 or col_now < 0 or row_now > N - 1 or col_now > N - 1) {
                continue;
            }
            if (visit[row_now][col_now]) {
                continue;
            }

           // printf("%d %d\n", row_now, col_now);
            visit[row_now][col_now] = true;
            q.push({row_now, col_now, count+1});
        }

    }
}

int main() {
    scanf("%d", &N);

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    BFS();

    if (minvalue == 99999)
        printf("%d", -1);
    else
         printf("%d", minvalue);

}