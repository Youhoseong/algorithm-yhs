
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int rootNode;
int bfs(vector<vector<int>> g, int startNode)
{
    queue<int> q;
    int countLeaf = 0;
    bool visited[51];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty())
    {
        int curNode = q.front();

        q.pop();

        if (curNode != rootNode and g[curNode].size() == 0)
        {
            countLeaf++;
        }
        if (g[curNode].size() != 0)
        {

            for (int i = 0; i < g[curNode].size(); i++)
            {
                int nextNode = g[curNode][i];

                if (!visited[nextNode])
                {
                    q.push(nextNode);
                    visited[nextNode] = true;
                }
            }
        }
    }

    return countLeaf;
}

int main()
{
    cin >> N;
    vector<vector<int>> graph;
    vector<int> ancestor;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        graph.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (temp != -1)
            graph[temp].push_back(i);
        else
            rootNode = i;

        ancestor.push_back(temp);
    }

    int deleteNode;
    cin >> deleteNode;

    if (deleteNode == rootNode)
    {
        cout << 0;
        return 0;
    }

    int entireLeaf = bfs(graph, rootNode);
    int deleteLeaf = bfs(graph, deleteNode);

    if (graph[ancestor[deleteNode]].size() == 1)
    {
        cout << entireLeaf - deleteLeaf + 1;
    }
    else
    {
        cout << entireLeaf - deleteLeaf;
    }
}
