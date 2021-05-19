#include <iostream>
#include <vector>

using namespace std;
int N;
int dp_sum[1001];
int dp_max_value[1001];
int A[1001];
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    dp_sum[1] = A[1];
    dp_max_value[1] = A[1];

    for (int i = 2; i <= N; i++)
    {
        int record_value;
        for (int j = i - 1; j >= 1; j--)
        {
            if (dp_max_value[j] > A[i])
            {
                dp_sum[i] = max(dp_sum[i], dp_sum[j] + A[i]);
                record_value = A[i];
            }
            else
            {
                if (A[i] < dp_sum[j])
                {
                    if (dp_sum[i] < dp_sum[j])
                    {
                        dp_sum[i] = dp_sum[j];
                        record_value = dp_max_value[j];
                    }
                }
                else
                {
                    if (dp_sum[i] < A[i])
                    {
                        dp_sum[i] = A[i];
                        record_value = A[i];
                    }
                }
            }
        }
        dp_max_value[i] = record_value;
    }
    //	for (int i = 1; i <= N; i++)
    //		cout << dp_sum[i] << " ";

    cout << dp_sum[N];
    //	for (int i = 1; i <= N; i++)
    //		cout << dp_max_value[i] << " ";
}