#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertionAtHead(Node * &head,int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }

    Node * newNode = new Node(data);

    newNode->next = head;
    head = newNode;
    
}

void insertionAtTail(Node * &head,int data){

    if(head == NULL){
        head = new Node(data);
        return;
    }

    Node * temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    Node * newNode = new Node(data);
    temp->next = newNode;

}

// K-Reverse
Node * kReverse(Node * head,int k){

    if(head == NULL){
        return NULL;
    }

    Node * prev = NULL;
    Node * curr = head;
    Node * temp;
    int c = 1;

    while(curr != NULL && c<=k){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        c++;
    }

    if(temp!=NULL){
        head->next = kReverse(temp,k);
    }

    return prev;
}


void printLinkedList(Node * head){

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){

    Node * head = NULL;
    insertionAtHead(head,1);
    insertionAtHead(head,0);
    insertionAtTail(head,2);
    insertionAtTail(head,3);
    insertionAtTail(head,4);
    insertionAtTail(head,5);
    insertionAtTail(head,6);
    printLinkedList(head);

    Node * kRev = kReverse(head,3);
    printLinkedList(kRev);



    return 0;
}
