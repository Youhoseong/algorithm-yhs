#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void changeStatus(vector<int> &light, int index){
    for(int i=index-1 ; i<=index+1 ; i++){
        if(i>=0 && i<light.size())
            light[i] = 1 - light[i];
    }
/*
    for(int i=0 ;i<light.size(); i++)
        cout << light[i] << " ";

    cout <<endl;
*/
}
int compareindex(vector<int> a, vector<int> b){
    int cnt=0;
    for(int i=0; i<a.size()-1; i++){
        if(a[i] != b[i]){
            changeStatus(a, i+1);
            cnt++;
        }

    }

    if(a == b){
        return cnt;
    }
    else
    {
        return -1;
    }
    
}


int main(){
    int N;
    cin >> N;
    vector<int> light(N);
    vector<int> wantTobe(N);

    string temp1, temp2;
    cin >> temp1;
    cin >> temp2;


    for(int i=0; i<N; i++){
        light[i] = (temp1[i]- '0');
    }    
    
    for(int i=0; i<N; i++){
        wantTobe[i] = temp2[i]- '0';
    }


    int notpress0 = compareindex(light, wantTobe);


    changeStatus(light, 0); // 0을 누름
    int press0 = compareindex(light, wantTobe);


    if(press0 != -1 && notpress0 != -1)
        cout << min(press0+1, notpress0) << '\n';
    else if(notpress0 != -1)
        cout << notpress0 << '\n';
    else if(press0 != -1)
        cout << press0+1 << '\n';
    else 
        cout << -1 << '\n';


    return 0;
}