
#include <bits/stdc++.h>
using namespace std;

//Replace with descendant Sum

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

int replaceWithSum(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int temp = root->data;
    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);

    root->data = leftSum + rightSum;

    return root->data + temp;
}

int main()
{

    Node *root = levelBuild();
    levelOrder(root);
    cout << endl;

    replaceWithSum(root);
    levelOrder(root);

    return 0;
}
