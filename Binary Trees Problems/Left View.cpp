#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

void solve(Node* root,vector<bool> &f,vector<int> &v,int i){
    
    if(root==NULL){
        return;
    }
    
    if(!f[i]){
        v.push_back(root->key);
        f[i] = true;
    }
    
    solve(root->left,f,v,i+1);
    solve(root->right,f,v,i+1);
}

vector<int> leftView(Node * root){
    //Complete the function
    
    int n = height(root);
    vector<bool> f(n,false);
    int i=1;
    vector<int> v;
    
    solve(root,f,v,i);
    return v;
}
