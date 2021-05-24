#include <iostream>
#include <queue>
using namespace std;

int S;
bool visited[1001][1001];
int BFS()
{
    int curS;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 0), 0)); // S, time
    visited[1][0] = true;
    while (!q.empty())
    {
        int curS = q.front().first.first;
        int curTime = q.front().first.second;
        int curCopy = q.front().second;

        q.pop();

        if (curS == S)
        {
            return curTime;
        }

        if (0 < curS and curS < 1001)
        {
            if (visited[curS][curS] != true)
            {
                q.push(make_pair(make_pair(curS, curTime + 1), curS)); // S, time
                visited[curS][curS] = true;
            }

            if (curCopy > 0 and (curS + curCopy) < 1001)
            {
                if (visited[curS + curCopy][curCopy] != true)
                {
                    q.push(make_pair(make_pair(curS + curCopy, curTime + 1), curCopy)); // S, time
                    visited[curS + curCopy][curCopy] = true;
                }
            }
            if (visited[curS - 1][curCopy] != true)
            {
                q.push(make_pair(make_pair(curS - 1, curTime + 1), curCopy)); // S, time
                visited[curS - 1][curCopy] = true;
            }
        }
    }
}

int main()
{
    cin >> S;
    cout << BFS();
}