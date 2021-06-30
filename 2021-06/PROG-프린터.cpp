#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (1) {
        int isBig = 0;

        for (int i = 0; i < priorities.size(); i++) {


            if (priorities[0] < priorities[i]) {
                priorities.push_back(priorities[0]);

                 if (location == 0) {
                     location = priorities.size() - 1;
                 }
                 priorities.erase(priorities.begin(), priorities.begin() + 1);

                 location -= 1;
                 isBig = 1;
                 break;

            }



        }

        if (isBig == 0) {
            answer++;

            if (location == 0) {
                break;
            }

            priorities.erase(priorities.begin(), priorities.begin() + 1);
            location -= 1;

        }


    }

    return answer;
}