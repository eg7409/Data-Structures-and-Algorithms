#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* lca(node*root, int a, int b){
    //Complete this function and return address of the node
    if(root==NULL){
        return NULL;
    }
    
    
    
    if(a <root->data && b<root->data){
        return lca(root->left,a,b);
    }
    else if(a>root->data && b>root->data){
        return lca(root->right,a,b);
    }
    else{
        return root;
    }
    
    
}
