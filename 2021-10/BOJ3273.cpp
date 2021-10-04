#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, X;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cin >> X;

    sort(v.begin(), v.end());

    int lp = 0;

    int rp = v.size() - 1;
    int answer = 0;
    while (lp < rp)
    {
        if (v[lp] + v[rp] == X)
        {
            answer++;
            lp++;
            rp--;
        }
        else if (v[lp] + v[rp] > X)
        {
            rp--;
        }
        else
        {
            lp++;
        }
    }

    cout << answer;
}