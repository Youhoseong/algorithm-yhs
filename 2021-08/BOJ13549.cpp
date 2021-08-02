#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

bool visited[200002];
void BFS()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, N});
    visited[N] = true;

    while (!q.empty())
    {

        int cur = q.top().second;

        int time = q.top().first;

        q.pop();

        if (cur == K)
        {
            cout << time;
            return;
        }

        if (cur * 2 <= 200000 and !visited[cur * 2])
        {
            q.push({time, cur * 2});
            visited[cur * 2] = true;
        }
        if (cur + 1 <= 200000 and !visited[cur + 1])
        {
            q.push({time + 1, cur + 1});
            visited[cur + 1] = true;
        }

        if (cur - 1 >= 0 and !visited[cur - 1])
        {
            q.push({time + 1, cur - 1});
            visited[cur - 1] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    BFS();
}