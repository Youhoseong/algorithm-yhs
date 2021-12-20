#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int N;

int parent[100001];
bool visited[100001];
void dfs(int startNode)
{

    for (int i = 0; i < v[startNode].size(); i++)
    {
        int nextNode = v[startNode][i];

        if (!visited[nextNode])
        {
            parent[nextNode] = startNode;
            visited[nextNode] = true;
            dfs(nextNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int temp1, temp2;

        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    visited[1] = true;

    dfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}