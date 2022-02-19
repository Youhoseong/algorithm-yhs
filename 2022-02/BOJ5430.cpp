#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int T;

deque<string> dq;

void doFunc(string func) {
    bool popFromFront = true;

    for(int i=0; i<func.size() ; i++){
        if(func[i] == 'R') {
            popFromFront = !popFromFront;
        } else {
            if(dq.empty()) {
                cout << "error" << '\n';
                return;
            } else {
                if(popFromFront) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }

            }

        }

    }

    if(dq.empty()) {
         cout << "[]" << '\n';
    } else {
        string result = "[";
        while (!dq.empty()) {
            if (popFromFront) {
                result += dq.front();
                result += ',';
                dq.pop_front();
            } else {
                result += dq.back();
                result += ',';
                dq.pop_back();
            }

        }
        result = result.substr(0, result.size() - 1);
        result += "]";

        cout << result << '\n';
    }

}
int main() {
    cin >> T;

    while(T--) {
        string func;
        int size;
        string ary;

        cin >> func;
        cin >> size;
        cin >> ary;

        ary = ary.substr(1, ary.size()-2);
        istringstream  ss(ary);
        string temp;


        while(getline(ss, temp, ',')) {
            dq.push_back(temp);
        }

        doFunc(func);
    }


}