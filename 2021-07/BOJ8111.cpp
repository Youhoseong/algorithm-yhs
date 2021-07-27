#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 20001;

bool visited[MAX];

pair<int, char> arr[MAX];
void bfs(int N)
{

    queue<int> q;
    q.push(1);
    visited[1] = true;
    arr[1].first = -1;
    arr[1].second = '1';

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            int next = (cur * 10 + i) % N;

            if (!visited[next])
            {
                arr[next].first = cur;
                arr[next].second = '0' + i;

                if (!next)
                    return;

                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void printPath(int num)
{

    if (num == -1)
        return;
    else
    {
        printPath(arr[num].first);
        cout << arr[num].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector<int> v;

    for (int i = 0; i < T; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    for (int i = 0; i < T; i++)
    {

        if (v[i] == 1)
        {
            cout << "1" << '\n';
            continue;
        }
        else
        {
            memset(visited, false, sizeof(visited));
            bfs(v[i]);
            printPath(0);

            cout << '\n';
        }
    }
}