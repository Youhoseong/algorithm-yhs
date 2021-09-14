#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<long long> liquid;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long temp;

        cin >> temp;

        liquid.push_back(temp);
    }

    sort(liquid.begin(), liquid.end());

    vector<long long> ans(3);
    long long zeroliquid = 3000000001;
    for (int i = 0; i < N - 2; i++)
    {

        int fp = i + 1;
        int ep = N - 1;

        while (fp < ep)
        {

            if (abs(zeroliquid) > abs(liquid[fp] + liquid[ep] + liquid[i]))
            {

                zeroliquid = liquid[fp] + liquid[ep] + liquid[i];

                ans[0] = liquid[i];
                ans[1] = liquid[fp];
                ans[2] = liquid[ep];

                if (zeroliquid == 0)
                    break;
            }

            if (liquid[fp] + liquid[ep] + liquid[i] > 0)
            {
                ep--;
            }
            else
            {
                fp++;
            }
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];
}