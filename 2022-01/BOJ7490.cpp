#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int k;

bool isZero(string value)
{
    int sum = 0;

    value.erase(remove(value.begin(), value.end(), ' '), value.end());

    int s = 0;
    for (int i = 0; i < value.size(); i++)
    {
        if (value[i] == '+' or value[i] == '-')
        {
            sum += stoi(value.substr(s, i - s));
            s = i;
        }
    }
    sum += stoi(value.substr(s));

    if (sum == 0)
        return true;
    else
        return false;
}

void printAll(int start, int end, string value)
{
    if (start == end)
    {
        value += to_string(start);

        if (isZero(value))
        {
            cout << value << '\n';
        }
    }
    else
    {
        value += to_string(start);

        printAll(start + 1, end, value + " ");
        printAll(start + 1, end, value + "+");
        printAll(start + 1, end, value + "-");
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin 속도 향상 위해

    cin >> k;

    while (k--)
    {
        int N;
        cin >> N;

        printAll(1, N, "");
        cout << '\n';
    }

    return 0;
}