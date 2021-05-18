#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int T;



void BFS(int init, int end){
    bool visited[10000]= {false,};
    queue<pair<int, string>> q;
    q.push({init,""});
    visited[init] = true;

    while(!q.empty()) {
        int curNum = q.front().first;
        string curInstruct = q.front().second;
        q.pop();
        if(curNum == end){
            cout << curInstruct << '\n'; //<< " " << curNum << endl;

            return;
        }

        int nextNum = (2 * curNum) % 10000;

        if (!visited[nextNum]){
            visited[nextNum] = true;
            q.push(make_pair(nextNum, curInstruct + "D"));
        }
        nextNum = (curNum - 1) < 0 ? 9999 : curNum - 1;
        if (!visited[nextNum]){
            visited[nextNum] = true;
            q.push(make_pair(nextNum, curInstruct + "S"));
        }

        //L

        nextNum = (curNum % 1000) * 10 + curNum / 1000;

        if (!visited[nextNum]){
            visited[nextNum] = true;
            q.push(make_pair(nextNum, curInstruct + "L"));
        }

        nextNum = (curNum % 10) * 1000 + (curNum / 10);
        if (!visited[nextNum]){
            visited[nextNum] = true;
            q.push(make_pair(nextNum, curInstruct + "R"));
        }


    }


}

int main() {
    cin >> T;
    while(T--) {
        //bool visited[10000];
        int A, B;
        cin >> A >> B;
        //for(int i=0; i<10000; i++)
        //    visited[i]=false;

        BFS(A,B);
    }

}