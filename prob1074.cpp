#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, row, col;

    cin >> N >> row >> col;

    int standX = pow(2, N) / 2;
    int standY = standX;
    int ans=0;

    for(int i=N-1; i>=0 ; i--){
        int diff = pow(2, i) / 2;
        int skip = pow(4, i);

        if(row < standY && col < standX) { // 1사분면
            standY -= diff;
            standX -= diff;
            cout << "1사분면:" << ans << endl;
        } 
        else if(row < standY && col >= standX) { //2사분면
            standY -= diff;
            standX += diff;
            ans += skip;
            cout << "2사분면:" << ans << endl;
        }
        else if(row >= standY && col <standX) { //3사분면
            standY += diff;
            standX -= diff;
            ans += skip * 2;
            cout << "3사분면:" << ans << endl;
        }
        else { //4사분면
            standY += diff;
            standX += diff;
            ans += skip * 3;
            cout << "4사분면:" << ans << endl;
        }

    }

    cout << ans << endl;

}