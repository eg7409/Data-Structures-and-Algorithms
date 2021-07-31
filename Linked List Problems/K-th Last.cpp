#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    
    
    
    node * fast = head;
    node* slow = head;
    
    while(k>0){
        fast = fast->next;
        k--;
    }
    
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow->data;
    
}
