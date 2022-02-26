#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct obj
{
    int from;
    int to;
    int value;
} Obj;

vector<Obj> map;
int N;
int parent[1000];

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
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int value;
            cin >> value;

            if (i < j)
            {
                map.push_back({i, j, value});
            }
        }
    }

    sort(map.begin(), map.end(), compare);

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    long long result = 0;
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

    cout << result << '\n';

    return 0;
}