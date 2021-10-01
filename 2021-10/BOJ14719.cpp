#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<int> v;
int main()
{
    cin >> H >> W;

    for (int i = 0; i < W; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> leftMax;
    vector<int> rightMax;

    int leftm = -1;
    int rightm = -1;
    for (int i = 0; i < W; i++)
    {
        leftm = max(leftm, v[i]);
        rightm = max(rightm, v[W - 1 - i]);
        leftMax.push_back(leftm);
        rightMax.push_back(rightm);
    }

    int cnt = 0;
    int mountWater = 0;
    for (int i = 0; i < W; i++)
    {
        mountWater += min(leftMax[i], rightMax[W - 1 - i]) - v[i];
    }

    cout << mountWater;
}