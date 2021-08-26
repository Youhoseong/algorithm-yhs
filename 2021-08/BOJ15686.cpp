#include <iostream>
#include <vector>
using namespace std;

#define INF 1111111111;
int N, M;

vector<pair<int, int>> home, chicken;
bool visited[13];

int answer = INF;

int calculateDistance(int homeRow, int homeCol, int chickenRow, int chickenCol)
{
    return abs(homeRow - chickenRow) + abs(homeCol - chickenCol);
}

void dfs(int index, int count)
{

    if (count == M)
    {
        int tempAnswer = 0;
        for (int i = 0; i < home.size(); i++)
        {
            int minDis = INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (visited[j])
                {

                    int distance = calculateDistance(home[i].first, home[i].second, chicken[j].first, chicken[j].second);
                    minDis = min(minDis, distance);
                }
            }

            tempAnswer += minDis;
        }

        answer = min(tempAnswer, answer);
    }
    else
    {
        if (index == chicken.size())
        {
            return;
        }

        visited[index] = true;
        dfs(index + 1, count + 1);

        visited[index] = false;
        dfs(index + 1, count);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;

            if (temp == 1)
            {
                home.push_back({i, j});
            }
            else if (temp == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    dfs(0, 0);

    cout << answer;
}