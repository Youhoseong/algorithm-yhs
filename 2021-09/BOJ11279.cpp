#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq;
    int N;

    cin >> N;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        if(temp != 0) {
            pq.push(temp);
        }
        else {
            if(pq.empty()) {
                printf("%d\n",0);
            }else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }


    }

    return 0;
}
