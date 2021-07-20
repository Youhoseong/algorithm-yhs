#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[20001];
//프로그래머스는 리턴 type을 맞추지 않으면 에러가 난다. (segment)

int maxDepth = 0;
int answer = 0;
vector<int> record;
void bfs(int startNode, vector<vector<int>> edge)
{

    queue<pair<int, int>> s;

    s.push({startNode, 0});
    visited[startNode] = true;

    while (!s.empty())
    {
        int curNode = s.front().first;
        int curEdgeCount = s.front().second;
        record.push_back(curEdgeCount);
        s.pop();
        //cout << "현재노드:" << curNode << " " << curEdgeCount << '\n';

        int nextNode = -99;

        for (int i = 0; i < edge.size(); i++)
        {
            if (edge[i][0] == curNode)
            {

                if (!visited[edge[i][1]])
                {
                    nextNode = edge[i][1];
                    s.push({nextNode, curEdgeCount + 1});
                    visited[nextNode] = true;
                }
            }
            else if (edge[i][1] == curNode)
            {

                if (!visited[edge[i][0]])
                {
                    nextNode = edge[i][0];
                    s.push({nextNode, curEdgeCount + 1});
                    visited[nextNode] = true;
                }
            }
        }
        if (nextNode == -99)
        {
            maxDepth = max(maxDepth, curEdgeCount);
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{

    bfs(1, edge);
    for (int i = 0; i < record.size(); i++)
    {
        if (record[i] == maxDepth)
            answer++;
    }

    return answer;
}