#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 100001

long long price[MAX];
long long dis[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++)
    {
        cin >> dis[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> price[i];
    }

    long long ans = 0;
    long long oil = price[1];
    for (int i = 1; i <= N - 1; i++)
    {

        if (price[i] < oil)
        {
            oil = price[i];
        }

        ans += oil * dis[i];
    }

    cout << ans;

    return 0;
}