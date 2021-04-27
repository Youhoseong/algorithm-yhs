#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int cnt=0;
vector<pair<int, int> > v;

void Hanoi(int N, int from, int by, int to) {
 
    if(N==1){
        v.push_back(make_pair(from, to));
        cnt++;
    }
    else {
        Hanoi(N-1, from, to, by);
        Hanoi(1, from, by, to);
        Hanoi(N-1, by, from, to);
    }
}

int main() {
    int N;
    cin >> N;
    Hanoi(N, 1, 2, 3);
    
    cout <<  cnt << '\n';
    for(int i=0; i<pow(2, N)-1; i++) {
        cout << v[i].first <<" " << v[i].second << '\n';
    }
   
    return 0;
}