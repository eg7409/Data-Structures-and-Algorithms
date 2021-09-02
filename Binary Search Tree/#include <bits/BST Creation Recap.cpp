#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node * left;
       Node * right;

       Node(int d){
           this->data = d;
           left = NULL;
           right = NULL;
       }
};

Node* insert(Node* root,int d){
    if(root == NULL){
        return new Node(d);
    }

    if(d < root->data){
        root->left = insert(root->left,d);
    }
    else{
        root->right = insert(root->right,d);
    }

    return root;
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){

    Node * root = NULL;
    vector<int> v = {8,3,10,1,6,14,4,7,13};

    for(auto i : v){
        root = insert(root,i);
    }

    inOrder(root);

    return 0;
}
