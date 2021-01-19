#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int length, width, height, N;
vector <pair<int, int> > v;

int ans;
int isfail=0;

void fillTheBox(int l, int w, int h, int index) {
        if(l == 0 || w == 0 || h == 0 ) 
            return;
        else {
            for(int i= index ; i>-1; i--){
                if(v[i].second > 0 && l >= v[i].first && w >= v[i].first && h >= v[i].first){
                    v[i].second--;
                    ans++;
                    fillTheBox(l-v[i].first, w, h, i);
                    fillTheBox(v[i].first, w-v[i].first, h, i);
                    fillTheBox(v[i].first, v[i].first, h-v[i].first, i);
                    return;
                }

            }


        }
    isfail=1;

}

int main() {
   

    cin >> length >> width >>  height;

    cin >> N;
 

    for(int i=0; i<N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back(make_pair(pow(2,temp1), temp2));
    }


    sort(v.begin(), v.end());

 
    fillTheBox(length, width, height, N-1);

    if(isfail)
        cout << -1 << '\n';
    else 
        cout << ans << '\n';


    return 0;
}