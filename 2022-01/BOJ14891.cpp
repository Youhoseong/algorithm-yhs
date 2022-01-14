#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;


vector<string> wheel;
int N;

bool visited[4];
void rotate(int dir, int cur) {
    char cur2 = wheel[cur][2];
    char cur6 = wheel[cur][6];

    if(dir == 1) {
        wheel[cur] = wheel[cur][7] + wheel[cur].substr(0, 7);
        visited[cur] = true;

    } else {
        wheel[cur] = wheel[cur].substr(1) + wheel[cur][0];
        visited[cur] = true;
    }
    int prev = cur - 1;
    int next = cur + 1;

    if(prev >= 0 && !visited[prev]) {
        if(wheel[prev][2] != cur6) {
            rotate(-dir, prev);
        }
    }

    if(next < 4 && !visited[next]) {
        if(wheel[next][6] !=  cur2) {
            rotate(-dir, next);
        }
    }

}


int main() {

    for(int i=1; i<=4; i++) {
        string temp1;
        cin >> temp1;

        wheel.push_back(temp1);
    }

    cin >> N;

    for(int i=0; i<N; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        memset(visited, false, sizeof(visited));
        rotate(temp2, temp1-1);
    }

    int answer = 0;
    int add = 1;
    for(int i=0; i<4; i++) {
        if(wheel[i][0] == '1') {
            answer += add;
        }
        add *= 2;
    }

    cout << answer;


}