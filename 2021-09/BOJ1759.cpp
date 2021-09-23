#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
int L, C;
bool visited[15];

bool checkIsSecret(string sec) {

    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0; i<sec.length(); i++) {
        if(sec[i] == 'a' or sec[i] == 'e' or sec[i] == 'i' or sec[i] == 'o' or sec[i] == 'u') {
            cnt1++;
        }else {
            cnt2++;
        }
    }

    if(cnt1 < 1 or cnt2 <2) {
        return false;
    }

    return true;
}


void bruteForce(int index, int cnt) {
    if(cnt==L) {
        string secret = "";
        for(int i=0; i<C; i++) {
            if(visited[i]) {
                secret += v[i];
            }
        }

        if(checkIsSecret(secret)) {
            cout <<secret <<'\n';
        }

    }else {
        if(index == C) {
            return;
        }else {
            visited[index]= true;
            bruteForce(index+1, cnt+1);

            visited[index] = false;
            bruteForce(index+1, cnt);

        }
    }
}

int main() {


    cin >> L >> C;

    for(int i=0; i< C ; i++){
        char temp;
        cin >> temp;

        v.push_back(temp);
    }


    sort(v.begin(), v.end());


    bruteForce(0,0);

}