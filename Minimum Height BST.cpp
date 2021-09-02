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
Node* minimumHeight(vector<int> v,int low,int high){
    
    if(low > high){
        return NULL;
    }

    int m = (high+low)/2;
    Node * root = new Node(v[m]);

    root->left = minimumHeight(v,low,m-1);
    root->right = minimumHeight(v,m+1,high);

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
    vector<int> v = {1,2,3,4,5,6,7};

    root = minimumHeight(v,0,v.size()-1);

    inOrder(root);

    return 0;
}
