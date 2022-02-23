#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;

typedef struct obj
{
    int from;
    int to;
    int value;
} Obj;

vector<Obj> map;

int parent[200001];

bool compare(Obj a, Obj b)
{
    if (a.value < b.value)
    {
        return true;
    }
    return false;
}

int find(int value)
{
    if (parent[value] == value)
    {
        return value;
    }
    else
    {
        return parent[value] = find(parent[value]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    while (1)
    {
        cin >> N >> M;

        if (N == 0 and M == 0)
        {
            break;
        }

        map.clear();
        int valuesum = 0;
        for (int i = 0; i < M; i++)
        {
            int from, to, value;

            cin >> from >> to >> value;
            map.push_back({from, to, value});
            valuesum += value;
        }

        sort(map.begin(), map.end(), compare);

        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
        }

        int result = 0;
        for (int i = 0; i < map.size(); i++)
        {
            int a = find(map[i].from);
            int b = find(map[i].to);

            if (a != b)
            {
                result += map[i].value;
                parent[a] = b;
            }
        }

        cout << valuesum - result << '\n';
    }

    return 0;
}