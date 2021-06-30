#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    queue<pair<int, int>> q;

    q.push({0, 0});

    cout << numbers.size();
    while (!q.empty())
    {
        int curCost = q.front().first;
        int curIndex = q.front().second;

        q.pop();

        if (curCost == target and curIndex == numbers.size())
        {
            answer++;
        }
        if (curIndex < numbers.size())
        {
            q.push({curCost + numbers[curIndex], curIndex + 1});
            q.push({curCost - numbers[curIndex], curIndex + 1});
        }
    }
    return answer;
}