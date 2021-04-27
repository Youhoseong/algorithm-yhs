#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <long long> v;

void findInteger(int N){
    int cnt=1;
    int maxcnt=-999;
    long long maxInteger = 0;
    long long prevInteger= v[0];
    for(int i=1 ; i<N ; i++){
        if(prevInteger == v[i]) {
            cnt++;
        }
        else {
            if(maxcnt < cnt) {
                maxcnt = cnt;
                maxInteger = prevInteger;
                cnt = 1;
            }
            else
            {
                cnt = 1;
            }

        }
    
        prevInteger = v[i];
    }
    if(maxcnt < cnt) {
        maxInteger = prevInteger;
    }
        

    cout << maxInteger << '\n';
}



int main() {
    int N;

    cin >> N;

    for(int i=0 ;i<N; i++){
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(int i=0 ;i<N; i++){
        cout << v[i] << " ";
    }
    cout << endl;


    findInteger(N);


    return 0;
}