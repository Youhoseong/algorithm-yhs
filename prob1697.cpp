#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;
bool visit[MAX] = {false,};

int BFS(int N, int K) {
    queue <pair <int, int > > v;
    
    v.push(make_pair(N, 0));
    visit[N] = true;


    while(!v.empty()) {
        int curLocation = v.front().first;
        int curTime = v.front().second;
        cout << curLocation << " " << curTime << endl;
        v.pop();

        if(curLocation == K){
            return curTime;
        }
        if((curLocation + 1 < MAX) && !visit[curLocation + 1]){
            v.push(make_pair(curLocation + 1 , curTime + 1));
            visit[curLocation + 1] = true;
        }
        if((curLocation - 1 >= 0) && !visit[curLocation - 1]){
            v.push(make_pair(curLocation - 1 , curTime + 1));
            visit[curLocation - 1] = true;
        }
        if((curLocation * 2 < MAX) && !visit[curLocation * 2]){
            v.push(make_pair(curLocation * 2 , curTime + 1));
            visit[curLocation * 2] = true;
        }
    }


}

int main() {
    int N, K;

    cin >> N >> K;

    int answer = BFS(N, K);
    cout << answer << '\n';



    return 0;
}