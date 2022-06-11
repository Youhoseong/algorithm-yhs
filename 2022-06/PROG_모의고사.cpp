#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int person1[5] = {1, 2, 3, 4, 5};
    int person2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int person3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int result[3] = {0, 0, 0};
    
    for(int j=0; j<answers.size(); j++) {
        if(answers[j] == person1[j%5]) {
            result[0]++;
        } 
        
        if(answers[j] == person2[j%8]) {
            result[1]++;
        }
        
        if(answers[j] == person3[j%10]) {
            result[2]++;
        }
        
    }
    
    int maxValue = *max_element(result, result+3);
    
    for(int i=0; i<3; i++) {
        if(result[i] == maxValue) {
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}