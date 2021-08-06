#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long M;
vector<long long> 예산;

bool possible(int mid)
{
    long long highCost;
    long long answer = 0;
    for (int i = 0; i < N; i++)
    {

        if (예산[i] <= mid)
        {
            answer += 예산[i];
        }
        else
        {
            answer += mid;
        }
    }

    if (answer <= M)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        예산.push_back(temp);
    }

    cin >> M;

    sort(예산.begin(), 예산.end());

    long long low = 1;
    long long high = 예산[N - 1];
    long long answer = 0;
    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (possible(mid))
        {
            answer = max(mid, answer);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << answer;
}
