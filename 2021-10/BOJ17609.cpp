#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp;

        cin >> temp;

        int leftp = 0;
        int rightp = temp.length() - 1;
        int flag = 0;

        while (leftp < rightp)
        {

            if (temp[leftp] != temp[rightp])
            {

                int templeft = leftp;
                int tempright = rightp;

                templeft++;

                int flag2 = 0;
                while (templeft < tempright)
                {
                    if (temp[templeft] != temp[tempright])
                    {
                        flag2 = 1;
                        break;
                    }
                    templeft++;
                    tempright--;
                }

                if (flag2 == 1)
                {
                    flag = 2;
                }
                else
                {
                    flag = 1;
                }

                if (flag != 1)
                {
                    flag2 = 0;
                    templeft = leftp;
                    tempright = rightp;

                    tempright--;
                    while (templeft < tempright)
                    {
                        if (temp[templeft] != temp[tempright])
                        {
                            flag2 = 1;
                            break;
                        }
                        templeft++;
                        tempright--;
                    }

                    if (flag2 == 1)
                    {
                        flag = 2;
                    }
                    else
                    {
                        flag = 1;
                    }
                }
            }

            if (flag > 0)
            {
                break;
            }

            leftp++;
            rightp--;
        }

        cout << flag << '\n';
    }
}