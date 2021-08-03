
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

1     
2 3   
4 5 6 
7  

*/

Node *levelOrderBuild()
{

    int d;
    cin >> d;

    Node *root = new Node(d);
    queue<Node *> q;
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
    Node *root = levelOrderBuild();
    levelOrder(root);

    return 0;
}
