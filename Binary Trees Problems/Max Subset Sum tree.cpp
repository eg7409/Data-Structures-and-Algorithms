
#include <bits/stdc++.h>
using namespace std;

//Max Subset Sum tree

/*
Input

1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1



Output

1     
2 3   
4 5 6 
7 

MAX : 18

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

class Pair{
    public:
    int inc;
    int exc;
};

Pair maxSubset(Node *root){

    Pair p;

    if(root == NULL){
        p.exc=0;
        p.inc=0;
        return p;
    }

    Pair LEFT = maxSubset(root->left);
    Pair RIGHT = maxSubset(root->right);

    p.inc = root->data + LEFT.exc + RIGHT.exc;
    p.exc = max(LEFT.inc, LEFT.exc) + max(RIGHT.exc,RIGHT.inc);

    return p;
}

int main()
{

    Node *root = levelBuild();
    levelOrder(root);

    Pair p = maxSubset(root);

    cout<<"MAX : "<<max(p.inc,p.exc)<<endl;

    return 0;
}
