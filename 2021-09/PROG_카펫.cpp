#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isBrownCanEstablish(int brown, int x, int y)
{
    if ((x + y) * 2 + 4 == brown)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    for (int i = 1; i * i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            if (isBrownCanEstablish(brown, i, yellow / i))
            {

                if (i > yellow / i)
                {
                    answer.push_back(i + 2);
                    answer.push_back(yellow / i + 2);
                }
                else
                {
                    answer.push_back(yellow / i + 2);
                    answer.push_back(i + 2);
                }

                break;
            }
        }
    }

    return answer;
}