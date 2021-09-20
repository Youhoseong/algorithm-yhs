#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> um;
    string answer = "";
    
    for(int i=0; i<completion.size(); i++) {
        um[completion[i]]++;
    }
    for(int i=0; i<participant.size(); i++) {
        um[participant[i]]--;
    }
    
    for(auto m : um) {
        if(m.second < 0) {
            answer = m.first;
            break;
        }
    }
    return answer;
}