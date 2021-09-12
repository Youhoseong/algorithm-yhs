#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> A;
vector<int> findInt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        findInt.push_back(temp);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < M; i++)
    {
        int flag = 1;
        int low = 0;
        int high = N - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (A[mid] == findInt[i])
            {
                printf("%d\n", 1);
                flag = 0;
                break;
            }

            if (A[mid] <= findInt[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (flag == 1)
        {
            printf("%d\n", 0);
        }
    }
}