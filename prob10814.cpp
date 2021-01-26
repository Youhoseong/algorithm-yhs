#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int, int> > v;
    string str[N];
    for(int i=0; i<N ;i++){
        int a;

        cin >> a >> str[i];
        v.push_back(make_pair(a, i));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<N; i++){
        cout << v[i].first <<  " " << str[v[i].second] << '\n';
    }
    


    return 0;
}