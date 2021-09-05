#include <bits/stdc++.h>
using namespace std;

class comp{
    public:
       bool operator()(int a,int b){
           return a < b;
       }
};

int main(){

    vector<int> v = {3,2,1,9,7,5,3,1,9};

    priority_queue<int> pq;

    for(auto i : v){
        pq.push(i);
    }

    priority_queue<int,vector<int>,greater<int> > q;

    for(auto i : v){
        q.push(i);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<endl;

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }

    cout<<endl;

    priority_queue<int,vector<int>,comp > p(v.begin(),v.end());

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }

    return 0;
}
