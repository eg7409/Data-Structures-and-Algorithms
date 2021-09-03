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

int closestNumber(Node* root,int target){
    int closest = 0;
    int diff = INT_MAX;

    int curr_diff;

    Node* temp = root;

    while(temp!=NULL){

        curr_diff = abs(temp->data - target);

        if(curr_diff == 0){
            return temp->data;
        }

        if(curr_diff < diff){
            diff = curr_diff;
            closest = temp->data;
        }

        if(temp->data < target){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }

    }

    return closest; 
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


    cout<<closestNumber(root,12);


    return 0;
}
