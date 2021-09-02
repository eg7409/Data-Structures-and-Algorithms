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

bool solve(Node* root,int k){
    if(root==NULL){
        return false;
    }
    if(root->key == k){
        return true;
    }
    else if(root->key > k){
        return solve(root->left,k);
    }
    else{
        return solve(root->right,k);
    }
}


bool isPresent(Node * root,int key){
    //Complete this method
    return solve(root,key);
    
}
