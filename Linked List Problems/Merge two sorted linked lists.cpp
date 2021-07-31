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

//Merge Two Sorted Linked List

Node * mergeLinkedList(Node * head1,Node * head2){

    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    if(head1->data < head2->data){
        head1->next = mergeLinkedList(head1->next,head2);
        return head1;
    }
    else{
        head2->next = mergeLinkedList(head1,head2->next);
        return head2;
    }

    
}


void printLinkedList(Node * head){

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){

    Node * head1 = NULL;
    Node * head2 = NULL;
    insertionAtTail(head1,1);
    insertionAtTail(head1,3);
    insertionAtTail(head1,5);
    
    insertionAtTail(head2,2);
    insertionAtTail(head2,4);
    insertionAtTail(head2,6);

    Node * m = mergeLinkedList(head1,head2);
    printLinkedList(m);



    return 0;
}
