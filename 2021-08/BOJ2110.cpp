#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
vector<int> coor;

bool isPossible(int dir)
{
    int cnt = 1;
    int compare = coor[0];

    for (int i = 1; i < N; i++)
    {
        if (coor[i] - compare >= dir)
        {
            cnt++;
            compare = coor[i];
        }
    }

    if (cnt >= K)
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        coor.push_back(temp);
    }

    sort(coor.begin(), coor.end());
    int low = 1;
    int high = coor[N - 1] - coor[0];

    int answer = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(mid))
        {
            answer = max(answer, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
}
