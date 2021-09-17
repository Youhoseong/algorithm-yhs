#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N;
char map[7][7];

vector<pair<int, int>> teacher;
vector<pair<int, int>> X;

bool checkObserv()
{
    bool flag = false;
    for (int i = 0; i < teacher.size(); i++)
    {
        int tRow = teacher[i].first;
        int tCol = teacher[i].second;

        for (int j = tRow; j >= 0; j--)
        {
            if (map[j][tCol] == 'O')
                break;
            else if (map[j][tCol] == 'S')
            {
                return false;
            }
        }
        for (int j = tRow; j < N; j++)
        {
            if (map[j][tCol] == 'O')
                break;
            else if (map[j][tCol] == 'S')
            {
                return false;
            }
        }
        for (int j = tCol; j >= 0; j--)
        {
            if (map[tRow][j] == 'O')
                break;
            else if (map[tRow][j] == 'S')
            {
                return false;
            }
        }
        for (int j = tCol; j < N; j++)
        {
            if (map[tRow][j] == 'O')
                break;
            else if (map[tRow][j] == 'S')
            {
                return false;
            }
        }
    }
    return true;
}

bool answer;
void bruteForce(int index, int objCount)
{
    if (objCount == 3)
    {

        if (!answer)
        {
            answer = checkObserv();
        }
        else
        {
            return;
        }
    }
    else
    {
        if (index == X.size())
        {
            return;
        }

        map[X[index].first][X[index].second] = 'O';
        bruteForce(index + 1, objCount + 1);

        map[X[index].first][X[index].second] = 'X';
        bruteForce(index + 1, objCount);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'X')
            {
                X.push_back({i, j});
            }
            else if (map[i][j] == 'T')
            {
                teacher.push_back({i, j});
            }
        }
    }
    bruteForce(0, 0);

    if (answer)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}