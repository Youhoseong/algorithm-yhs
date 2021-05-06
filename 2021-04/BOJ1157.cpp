#include <iostream>
#include <string>
#include <locale>
using namespace std;

int alphaCount[26];

int main() {
    string str;
    cin >> str;

    for(int i=0; i<str.length(); i++){
        str[i] = toupper(str[i]);
        alphaCount[str[i]- 'A']++;
    }
    
    int max=0;
    char answer;


    for(int i=0; i<26; i++){
        if(max < alphaCount[i]){
            max = alphaCount[i];
            answer = i + 'A';
        }
    }
    int maxCount = 0;
    for(int i=0; i<26; i++){
        if(max == alphaCount[i]){
            maxCount++;
            if(maxCount >=2){
                answer = '?';
                break;
            }
        }
    }
    
    
    printf("%c", answer);

}