
#include <iostream>
#include <vector>
using namespace std;

int N; 
vector<vector <int> > map(20, vector<int>(20));
vector<int> gen(int k){
    vector <int> a(5);
    for(int i=0; i<5; i++){
        a[i] = (k & 3);
        k >>= 2;
    }

    return a;
}

int check(vector<int> &dirs) {
    int n = map.size();
    vector<vector< pair<int, bool> > > d(n, vector<pair<int, bool> >(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            d[i][j].first = map[i][j];
        }

    }

    // 0: down 1: up 2:left 3:right

    for(int dir: dirs) {
        bool ok = false;
        for(int i=0; i<n; i++){ // second init
            for(int j=0; j<n; j++)
                d[i][j].second = false;

        }

        while(true) {
            ok =false;
            if(dir ==0) {//down
                for(int i= n-2 ; i>=0 ; i--) {
                    for(int j=0; j<n ;j++) {
                        if(d[i][j].first == 0) continue;
                        if(d[i+1][j].first == 0) {
                            //옮겨야지
                            d[i+1][j].first = d[i][j].first;
                            d[i+1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok =true;
                        }
                        else if(d[i+1][j].first == d[i][j].first) {
                            //합쳐야지
                            if(d[i][j].second ==false && d[i+1][j].second == false){
                                d[i+1][j].first *=2;
                                d[i+1][j].second = true;
                                d[i][j].first=0;
                                ok=true;
                            }
                        }
                    }
                }
            }
            else if(dir == 1){
                for(int i=1 ; i<=n-1 ; i++) {
                    for(int j=0; j<n; j++) {
                        if(d[i][j].first == 0) continue;
                        if(d[i-1][j].first ==0) {
                            //옮겨야지
                            d[i-1][j].first = d[i][j].first;
                            d[i-1][j].second = d[i][j].second;

                            d[i][j].first =0;
                            ok=true;
                        }
                        else if(d[i-1][j].first == d[i][j].first) {
                            if(d[i][j].second == false && d[i-1][j].second == false) {
                                d[i-1][j].first *= 2;
                                d[i-1][j].second = true;
                                d[i][j].first=0;
                                ok=true;
                            }

                        }
                    }
                }
            }

            else if(dir == 2){ //left
                for(int j=1 ; j<=n-1 ; j++) {
                    for(int i=0; i<n; i++) {
                        if(d[i][j].first == 0) continue;
                        if(d[i][j-1].first ==0) {
                            //옮겨야지
                            d[i][j-1].first = d[i][j].first;
                            d[i][j-1].second = d[i][j].second;

                            d[i][j].first =0;
                            ok=true;
                        }
                        else if(d[i][j-1].first == d[i][j].first) {
                            if(d[i][j].second == false && d[i][j-1].second == false) {
                                d[i][j-1].first *= 2;
                                d[i][j-1].second = true;
                                d[i][j].first=0;
                                ok=true;
                            }
                        }
                    }
                }
            }

            else if(dir == 3){ //right
                for(int j=n-2 ; j>=0 ; j--) {
                    for(int i=0; i<n; i++) {
                        if(d[i][j].first == 0) continue;
                        if(d[i][j+1].first ==0) {
                            //옮겨야지
                            d[i][j+1].first = d[i][j].first;
                            d[i][j+1].second = d[i][j].second;

                            d[i][j].first =0;
                            ok=true;
                        }
                        else if(d[i][j+1].first == d[i][j].first) {
                            if(d[i][j].second == false && d[i][j+1].second == false) {
                                d[i][j+1].first *= 2;
                                d[i][j+1].second = true;
                                d[i][j].first=0;
                                ok=true;
                            }
                        }
                    }
                }
            }
            if(ok==false) break;


        }

    }
    int ans =0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ans < d[i][j].first) {
                ans = d[i][j].first;

            }

        }


    }
    return ans;
}



int main() {
    cout << "enter N:";
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> map[i][j];
    }

    int ans = 0;

    for(int i=0; i< (1 << 10); i++) { // case 4^5
        vector<int> dir = gen(i); // i를 4진수로 변환함
        int cur = check(dir);
        if(ans < cur) ans = cur;
    }
    cout << ans << endl;

    return 0;
}

