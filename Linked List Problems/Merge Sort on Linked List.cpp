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


// pointer at mid
Node * getMid(Node *head){
  
    
    Node * slow = head;
    Node * fast = head;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

//sorting linked list
Node * mergeSort(Node * head){

    if(head == NULL || head->next== NULL){
        return head;
    }

    Node * mid = getMid(head);

    Node * a = head;
	Node * b = mid->next;
	mid->next = NULL;   //Breaking the link

	
	a = mergeSort(a);
	b = mergeSort(b);


    return mergeLinkedList(a,b);
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

    insertionAtTail(head,7);
    insertionAtTail(head,8);
    insertionAtTail(head,9);
    insertionAtTail(head,6);
    insertionAtTail(head,7);
    insertionAtTail(head,6);
    insertionAtTail(head,7);
    insertionAtTail(head,1);
    
    printLinkedList(head);

    Node * m = mergeSort(head);

    printLinkedList(m);


    return 0;
}
