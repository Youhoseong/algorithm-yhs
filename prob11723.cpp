#include <iostream>

using namespace std;

int N;
int bitmask;
string oper;
int x;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for(int i=0 ;i<N; i++){
        oper.clear();
        cin >> oper;
        
        if(oper == "add"){
            cin >> x;
            bitmask |= (1 << x);
        }
        else if(oper == "remove") {
            cin >> x;
            bitmask &= ~(1 << x);
        }
        else if(oper == "check") {
            cin >> x;
            if(bitmask & (1 << x) )
                cout << "1" << endl;
            else 
                cout << "0" << endl;

        }
        else if(oper == "toggle") {
            cin >> x;
            bitmask ^= (1 << x);
        }
        else if(oper == "all") {
            bitmask = (1 << 21) -1;
        }
        else if(oper == "empty") {
            bitmask = 0;
        }

    }


    return 0;
}