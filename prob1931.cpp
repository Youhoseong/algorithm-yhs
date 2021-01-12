#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> &a,  pair<int, int> &b){
    if(b.second == a.second){
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }

} 

int main() {
    int N, start, end;

    cin >> N;

    vector <pair<int, int> > v;

    for(int i=0; i<N; i++){
        cin >>  start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), compare);

    int oldendtime= v[0].second;
    int cnt=1;

    for(int i=1; i<N; i++){
        if(oldendtime <= v[i].first){
            cnt++;
            oldendtime = v[i].second;
        }

    }

    cout << cnt <<endl;
}