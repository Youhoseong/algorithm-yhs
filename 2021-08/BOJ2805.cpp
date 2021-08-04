#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
vector<long long> trees;

bool possible(int mid)
{
    long long allParts = 0;

    for (int i = 0; i < N; i++)
    {
        if (trees[i] > mid)
        {
            allParts += trees[i] - mid;
        }
    }

    if (allParts >= M)
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
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {

        long long temp;
        cin >> temp;
        trees.push_back(temp);
    }

    sort(trees.begin(), trees.end());

    long long low = 0;
    long long high = trees[N - 1];

    long long maxHeight = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (possible(mid))
        {
            maxHeight = max(maxHeight, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << maxHeight;
}
