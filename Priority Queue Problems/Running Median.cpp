#include <bits/stdc++.h>
using namespace std;


/* 

Time complexity - O ( N Log N ) 

O(Log n) - for each insertion
O(1) - each query
O(NLogN) = for insertion

*/
int main(){

    priority_queue<int> max_heap;
    priority_queue<int,vector<int> , greater<int> > min_heap;

    int d;
    cin>>d;

    max_heap.push(d);
    float median = d;
    cout<<median<<" ";


    cin>>d;

    while(d!=-1){

        if(max_heap.size() > min_heap.size()){
            if(d > median){
                min_heap.push(d);
            }
            else{
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(d);
            }
            median = (max_heap.top() + min_heap.top())/2.0;
        }
        else if(max_heap.size() < min_heap.size()){
            if(d < median){
                max_heap.push(d);
            }
            else{
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(d);
            }
            median = (max_heap.top() + min_heap.top())/2.0;
        }
        else{
            if(d < median){
                max_heap.push(d);
                median = max_heap.top();
            }
            else{
                min_heap.push(d);
                median = min_heap.top();
            }
        }
        cout<<median<<" ";
        cin>>d;
    }

    return 0;
}
