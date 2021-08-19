#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    int start;
    int end;
    int term;
};

bool compare(const info &p1, const info &p2)
{
    if (p1.start == p2.start)
    {
        return p1.term > p2.term;
    }
    else
    {
        return p1.start < p2.start;
    }
}

int N;

int calendar[366];

int main()
{
    info in[1001];

    cin >> N;

    for (int i = 0; i < N; i++)
    {

        int s, e;

        cin >> s >> e;

        in[i].start = s;
        in[i].end = e;
        in[i].term = e - s + 1;
    }

    sort(in, in + N, compare);

    for (int i = 0; i < N; i++)
    {

        int start = in[i].start;
        int end = in[i].end;

        for (int j = start; j <= end; j++)
        {
            calendar[j]++;
        }
    }

    int maxRow = 0;
    int col = 0;
    int answer = 0;
    for (int i = 0; i <= 365; i++)
    {
        if (calendar[i] != 0)
        {

            maxRow = max(maxRow, calendar[i]);
            col++;
        }
        else
        {
            answer += (maxRow * col);
            col = 0;
            maxRow = 0;
        }
    }
    answer += col * maxRow;

    cout << answer;
}
