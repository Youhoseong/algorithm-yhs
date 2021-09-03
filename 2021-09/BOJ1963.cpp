#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;


int T;
bool ary[10001];
int from, to;
bool visited[10001];
int bfs(){
    queue<pair<int,int>> q;

    q.push({from , 0});

    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == to) {

            return cnt;
        }
        int digit[4] = {cur / 1000, (cur % 1000)/ 100,  (cur% 100) / 10, cur % 10};

        for(int i=0; i<4; i++){
            int jstart= 0;
            if(i == 0) {
                jstart = 1;
            }

            for(int j = jstart; j<10 ; j++){
                int next = 0;

                for(int k=0; k<4; k++){
                    if(k==i) {
                        next += j * pow(10, 3-k);
                    } else {
                        next += digit[k] * pow(10, 3-k);

                    }

                }

                if(!ary[next] && !visited[next]) {
                    visited[next] = true;
                    q.push({next, cnt+1});
                }
            }

        }

    }
    return -1;
}


int main(){

    for(int i=2; i<=10000; i++) {
        if(ary[i]) {
            continue;
        }

        for(int j=i+i; j<=10000; j+= i){
            ary[j] = true;

        }

    }

    cin >> T;


    while(T--) {
        memset(visited,false, sizeof(visited));


        cin >> from >> to;

        int result = bfs();

        if(result == -1) {
            cout << "Impossible" << '\n';
        } else {
            cout << result << '\n';
        }



    }


}

