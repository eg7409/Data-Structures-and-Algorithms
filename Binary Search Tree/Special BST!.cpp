#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

Node* findInOrderSuccessor( Node *target ){
    //Complete this Method, return the pointer to the inorder successor
    // HINT : Since the parent pointer is given, you can traverse upwards in the tree
    if(target == NULL){
        return NULL;
    }
    
    if(target->right==NULL){
        //return target->parent;
        if(target->parent->key > target->key){
            return target->parent;
        }
        
        Node * temp = target->parent->parent;
        
        while(temp!=NULL){
            if(temp->parent == NULL){
                break;
            }
            if(temp->right!=NULL && temp->right->key > target->key){
                Node * t = temp->right;
                if(t->left!=NULL){
                    t = t->left;
                    while(t!=NULL){
                        t = t->left;
                    }
                }
                temp = t;
            }
            else{
                temp = temp->parent;
            }
        }
        return temp;
    }
    
    Node * temp = target->right;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
    
    
}
