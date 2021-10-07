#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N;
vector<long long> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long l;
        cin >> l;

        v.push_back(l);
    }

    int lp = 0;
    int rp = v.size() - 1;
    int recordlp = 0;
    int recordrp = 0;
    long long zero = 2000000001;
    while (lp < rp)
    {

        if (abs(v[lp] + v[rp]) <= abs(zero))
        {
            zero = v[lp] + v[rp];
            recordlp = lp;
            recordrp = rp;

            if (zero == 0)
            {
                break;
            }
        }

        if (v[lp] + v[rp] > 0)
        {
            rp--;
        }
        else
        {
            lp++;
        }
    }
    cout << v[recordlp] << " " << v[recordrp];
}