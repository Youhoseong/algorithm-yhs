#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> vec[32001];
int cntPreBuild[32001];
vector<int> answer;
void bfs()
{

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (cntPreBuild[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curBuild = q.front();
        q.pop();
        answer.push_back(curBuild);

        for (int i = 0; i < vec[curBuild].size(); i++)
        {
            int nextBuild = vec[curBuild][i];

            if (--cntPreBuild[nextBuild] == 0)
            {
                q.push(nextBuild);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int T;
        cin >> T;
        vector<int> v;
        for (int j = 0; j < T; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        for (int j = 0; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                vec[v[j]].push_back(v[k]);
                cntPreBuild[v[k]]++;
            }
        }
    }

    bfs();

    if (answer.size() != N)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << answer[i] << endl;
        }
    }
}