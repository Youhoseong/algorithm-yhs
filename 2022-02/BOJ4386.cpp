#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 100001

int N;

typedef struct obj
{
    int from;
    int to;
    double value;
} Obj;

vector<Obj> map;
vector<pair<double, double>> temp;

int parent[100];

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
        return find(parent[value]);
    }
}

double calDistance(pair<double, double> a, pair<double, double> b)
{

    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        double from, to;

        cin >> from >> to;
        temp.push_back({from, to});
    }

    for (int i = 0; i < N; i++)
    {
        pair<double, double> p = temp[i];
        for (int j = i + 1; j < N; j++)
        {
            pair<double, double> m = temp[j];

            double distance = calDistance(p, m);

            map.push_back({i, j, distance});
        }
    }

    sort(map.begin(), map.end(), compare);

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    double result = 0;
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

    printf("%.2f", result);

    return 0;
}