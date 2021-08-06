
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

class HDPair
{
public:
    int height;
    int diamter;
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

HDPair optimizedDiameter(Node *root)
{
    HDPair p;

    if (root == NULL)
    {
        p.height = 0;
        p.diamter = 0;
        return p;
    }

    HDPair left = optimizedDiameter(root->left);
    HDPair right = optimizedDiameter(root->right);

    p.height = 1 + max(left.height, right.height);

    int d1 = left.height + right.height;
    int d2 = left.diamter;
    int d3 = right.diamter;

    p.diamter = max(d1, max(d2, d3));

    return p;
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
    cout << optimizedDiameter(root).diamter << endl;

    return 0;
}
