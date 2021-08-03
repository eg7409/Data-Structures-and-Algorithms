
#include <bits/stdc++.h>
using namespace std;

//Level Order Print

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

Node *buildTree()
{

    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *n = new Node(d);

    n->left = buildTree();
    n->right = buildTree();

    return n;
}

/*

Input

1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1


Output

1     
2 3   
4 5 6 
7

*/

//BFS - queues

void levelOrder(Node *root)
{

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        if (temp == NULL)
        {
            cout << endl;

            q.pop();

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{

    Node *root = buildTree();
    levelOrder(root);

    return 0;
}
