
#include <bits/stdc++.h>
using namespace std;

//Print at Level K

/*
Input

1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1



Output

  
4 5 6 


*/

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

void levelOrder(Node *root, int k)
{

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();

        if (curr == NULL)
        {
            k--;
            q.pop();
            //cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (k == 0)
            {
                cout << curr->data << " ";
            }

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

int main()
{

    Node *root = levelBuild();

    int k = 2;
    levelOrder(root, k);

    return 0;
}
