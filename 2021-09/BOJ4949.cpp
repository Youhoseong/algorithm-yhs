#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {


    while(1) { 
        stack<char> s;
        string temp;
//        cout << "대기: ";
        getline(cin, temp);

        int error= 0;
        int lineend = 0;
        int end = 0;

        for(int i=0; i<temp.length(); i++){
            if(temp[i] == '('){
                s.push(temp[i]);
            }else if(temp[i] == ')'){
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    error = 1;
                    lineend = 1;
                    break;
                }
            }else if(temp[i] == '['){
                s.push(temp[i]);
            }else if(temp[i] == ']'){
                if(s.size() > 0 && s.top() == '[')
                    s.pop();
                else {
                    error = 1;
                    lineend = 1;
                    break;
                }
            }else if(temp[i] == '.') {

                if(i == 0){
                    end = 1;
                }
                lineend = 1;
//
//                cout << "len:" << i << endl;
//                cout << "end:" << end << endl;
                break;
            }
        }


        if(end == 1) {
            break;
        }
        else if(lineend == 1) {
            if(error or !s.empty()) {
                printf("no\n");
            } else {
                printf("yes\n");
            }
        }

    }

}