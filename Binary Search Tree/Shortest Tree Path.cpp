#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

node* lca(node*root, int a, int b){
 
    if(root==NULL){
        return NULL;
    }
    
    if(a <root->key && b<root->key){
        return lca(root->left,a,b);
    }
    else if(a>root->key && b>root->key){
        return lca(root->right,a,b);
    }
    else{
        return root;
    }
    
}


int l(node * root,int a){
    
    int c = 0;
    
    if(root==NULL){
        return 0;
    }
    
    if(root->key == a){
        return c;
    }
    
    else if(root->key > a){
        c+= 1 + l(root->left,a);
    }
    else{
        c+= 1+ l(root->right,a);
    }
    return c;
}


//here nodes a and b are the inputs
int shortestDist(node * root,int a,int b){
    //Complete this method
    
    
    node * f = lca(root,a,b);
    
    int c1 = l(f,a);
    int c2 = l(f,b);
    
    return c1+c2;
    
    
}
