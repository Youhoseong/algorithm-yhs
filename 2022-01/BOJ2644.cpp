#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int person;
int N;
bool visited[101];
vector<int> relation[101];

void bfs(int start, int end)
{
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, 0});

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (cur == end)
        {
            cout << cnt << '\n';
            return;
        }

        for (int i = 0; i < relation[cur].size(); i++)
        {
            int next = relation[cur][i];

            if (!visited[next])
            {
                q.push({next, cnt + 1});
                visited[next] = true;
            }
        }
    }

    cout << -1 << '\n';
}

int main()
{
    int start, end;
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    cin >> person;

    cin >> start >> end;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        relation[temp1].push_back(temp2);
        relation[temp2].push_back(temp1);
    }

    bfs(start, end);

    return 0;
}