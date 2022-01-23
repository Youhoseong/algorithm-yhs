#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    string str;
    cin >> str;

    bool isZero = false;

    int cnt3 = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] - '0' == 0)
        {
            isZero = true;
        }
        else
        {
            cnt3 += str[i] - '0';
        }
    }

    if (isZero && (cnt3 % 3 == 0))
    {

        sort(str.begin(), str.end(), greater<char>());
        cout << str;
    }
    else
    {
        cout << -1;
    }

    return 0;
}