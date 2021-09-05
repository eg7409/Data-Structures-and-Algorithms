#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v,int n){
    priority_queue<int,vector<int> ,greater<int> > pq(v.begin(),v.end());
    int c = 0;

    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        int p = x+y;
        c+=p;
        pq.push(p);
    }
    cout<<c<<endl;
}

int main(){

    vector<int> v = {4,3,2,6};
    int n = v.size();

    solve(v,n);

    return 0;
}
