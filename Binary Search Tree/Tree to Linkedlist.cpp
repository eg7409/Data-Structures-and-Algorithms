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

class LinkedList{
    public:
       Node* head;
       Node * tail;
};

LinkedList treeToList(Node * root){
    LinkedList l;

    if(root == NULL){
        l.head = NULL;
        l.tail = NULL;

        return l;
    }

    if(root->left == NULL && root->right == NULL){
        l.head = root;
        l.tail = root;
    }
    else if(root->left != NULL && root->right == NULL){
        LinkedList leftLL = treeToList(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left == NULL && root->right != NULL){
        LinkedList rightLL = treeToList(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else{
        LinkedList leftLL = treeToList(root->left);
        LinkedList rightLL = treeToList(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
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

    LinkedList l = treeToList(root);
    Node * temp = l.head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    
    return 0;
}
