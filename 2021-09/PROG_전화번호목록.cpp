#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    for(int i=0;  i<phone_book.size();i++) {
        um[phone_book[i]] = i;
    }
    
    for(int i=0; i<phone_book.size() ; i++) {
       
        string phone = "";
        for(int j=0; j<phone_book[i].size(); j++) {
           phone += phone_book[i][j];
            if(um.find(phone) != um.end() && phone != phone_book[i]) {
                return false;
            }
       }
        

    }
    
    
    return true;
}