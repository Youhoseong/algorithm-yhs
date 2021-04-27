#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

int main() {
    string S, T;

    cin >> S;
    cin >> T;

    while(1) {
        if(S.length() == T.length()) {
            if(S == T){
                cout << 1 << endl;
                return 0;
            }
            break;
        }

        char temp = T.back();
        cout <<  temp << endl;
        T.pop_back();

        if(temp == 'B') {
            reverse(T.begin(), T.end());
        }

    }
    cout << 0 << endl;
    return 0;
}