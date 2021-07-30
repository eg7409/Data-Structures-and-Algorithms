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

Node* recursiveReverse(Node * head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node * rec = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rec;
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

    printLinkedList(head);
    Node * rev = recursiveReverse(head);

    printLinkedList(rev);


    return 0;
}
