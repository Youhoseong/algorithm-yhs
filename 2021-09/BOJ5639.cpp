#include <iostream>

#include <string.h>

using namespace std;

int tree[1000001][2];

void preorder(int root, int cur)
{
    if (cur > root)
    {
        if (!tree[root][1])
        {
            tree[root][1] = cur;
            return;
        }
        else
        {
            preorder(tree[root][1], cur);
        }
    }
    else
    {
        if (!tree[root][0])
        {
            tree[root][0] = cur;
            return;
        }
        else
        {
            preorder(tree[root][0], cur);
        }
    }
}

void postorder(int root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        postorder(tree[root][0]);
        postorder(tree[root][1]);

        cout << root << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int root, n;

    cin >> root;
    memset(tree, 0, sizeof(tree));

    while (cin >> n)
    {
        preorder(root, n);
    }

    postorder(root);
}