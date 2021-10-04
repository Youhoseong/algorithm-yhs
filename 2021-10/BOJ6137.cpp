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

    vector<char> v;

    for (int i = 0; i < N; i++)
    {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    int lp = 0;
    int rp = v.size() - 1;
    string answer = "";
    int cnt = 1;
    while (lp <= rp)
    {
        if (v[lp] > v[rp])
        {
            answer += v[rp];
            rp--;
        }
        else if (v[lp] < v[rp])
        {
            answer += v[lp];
            lp++;
        }
        else
        {
            int templp = lp + 1;
            int temprp = rp - 1;
            int flag = 0;
            while (templp <= temprp)
            {

                if (v[templp] > v[temprp])
                {
                    answer += v[rp];
                    rp--;
                    flag = 1;
                    break;
                }
                else if (v[templp] < v[temprp])
                {
                    answer += v[lp];
                    lp++;
                    flag = 1;
                    break;
                }
                else
                {
                    templp++;
                    temprp--;
                }
            }

            if (!flag)
            {
                answer += v[lp];
                lp++;
            }
        }
    }

    for (int i = 0; i < answer.length(); i++)
    {
        cout << answer[i];

        if (!((i + 1) % 80))
            cout << '\n';
    }
}