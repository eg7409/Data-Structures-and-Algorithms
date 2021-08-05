
#include <bits/stdc++.h>
using namespace std;

//Level Order Build

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

5

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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
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

int main()
{

    Node *root = levelBuild();

    cout << diameter(root) << endl;

    return 0;
}
