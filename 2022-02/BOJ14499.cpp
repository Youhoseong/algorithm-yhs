#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[20][20];

int dice[6] = {0,0,0,0,0,0};

bool isCanMove(int dir) {
    if(dir == 1) {
        if(y + 1 < M) {
            return true;
        }
    } else if(dir == 2) {
        if(y-1 >= 0) {
            return true;
        }
    } else if(dir == 3) {
        if( x- 1 >= 0) {
            return true;
        }
    } else {
        if( x+1 < N) {
            return true;
        }
    }

    return false;

}
void moveDice(int dir) {


    if(dir == 1) {
        y++;
        int temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    } else if(dir == 2) {
        y--;
        int temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    } else if(dir == 3) {
        x--;
        int temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    } else {
        x++;
        int temp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }

}

void doCopy() {
    if(map[x][y] == 0) {
        map[x][y] = dice[5];
    } else {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }

}


int main() {

    cin >> N >> M >> x >> y >> K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    doCopy();

    while(K--) {
        int m;
        cin >> m;
        if(isCanMove(m)) {
            moveDice(m);
            doCopy();
            cout << dice[0] << '\n';
        } else {
            continue;
        }




    }




}