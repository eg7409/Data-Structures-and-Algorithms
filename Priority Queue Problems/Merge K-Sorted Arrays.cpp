#include<bits/stdc++.h>
using namespace std;


vector<int> mergeKArrays(vector<vector<int> > v){
    //Complete this function
    int k = v.size();

    priority_queue<vector<int> , vector<vector<int> > , greater<vector<int> > > pq;

    for(int i=0;i<k;i++){
        pq.push({v[i][0],i,0});
    }

    vector<int> output;

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int element = top[0];
        int a_ind = top[1];
        int e_ind = top[2];

        output.push_back(element);

        if(e_ind + 1 < v[a_ind].size()){
            pq.push({v[a_ind][e_ind+1],a_ind,e_ind+1});
        }
    }
    return output;
    
}
