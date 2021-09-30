#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int> pq;
    bool isAvailable[200000];
    int classCnt = 0;

    int N;
    vector<pair<int, int>> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;

        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }

    sort(v.begin(), v.end());

    pq.push(-v[0].second);
    int ans = 0;

    for (int i = 1; i < N; i++)
    {
        while (!pq.empty())
        {
            if (-pq.top() <= v[i].first)
            {
                pq.pop();
            }
            else
            {
                break;
            }
        }
        pq.push(-v[i].second);
        ans = max(ans, (int)pq.size());
    }

    cout << ans;
}