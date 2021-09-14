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

    int fp = 0;
    int ep = N - 1;

    long long ans1, ans2;
    long long zeroliquid = 2000000001;
    while (fp < ep)
    {

        if (abs(zeroliquid) > abs(liquid[fp] + liquid[ep]))
        {
            ans2 = min(liquid[fp], liquid[ep]);
            ans1 = max(liquid[fp], liquid[ep]);

            zeroliquid = liquid[fp] + liquid[ep];

            if (zeroliquid == 0)
                break;
        }

        if (liquid[fp] + liquid[ep] > 0)
        {
            ep--;
        }
        else
        {
            fp++;
        }
    }

    cout << ans2 << " " << ans1;
}