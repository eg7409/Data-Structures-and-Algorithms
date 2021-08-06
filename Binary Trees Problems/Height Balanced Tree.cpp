
#include <bits/stdc++.h>
using namespace std;

//Height Balanced Tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*


Input

1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1


Output

Balanced Binary Tree

*/

void levelOrder(Node *root)
{

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();

        if (curr == NULL)
        {
            q.pop();
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";
            q.pop();

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

Node *levelBuild()
{

    int d;
    cin >> d;

    queue<Node *> q;
    Node *root = new Node(d);
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();

        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            curr->left = new Node(c1);
            q.push(curr->left);
        }
        if (c2 != -1)
        {
            curr->right = new Node(c2);
            q.push(curr->right);
        }
    }

    return root;
}

pair<int, bool> isHeightBalanced(Node *root)
{

    pair<int, bool> p, left, right;

    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }

    left = isHeightBalanced(root->left);
    right = isHeightBalanced(root->right);

    p.first = 1 + max(left.first, right.first);

    if (abs(left.first - right.first) <= 1 && left.second && right.second)
    {
        return {p.first, true};
    }

    return {p.first, false};
}

int main()
{

    Node *root = levelBuild();

    if (isHeightBalanced(root).second)
    {
        cout << "Balanced Binary Tree";
    }
    else
    {
        cout << "NOT balanced!!";
    }

    return 0;
}
