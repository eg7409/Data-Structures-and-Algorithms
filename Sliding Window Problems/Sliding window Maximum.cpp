#include<bits/stdc++.h>
using namespace std;

//Sliding window Maximum
vector<int> maxInWindow(vector<int> v,int k){
    
    int n = v.size();
    deque<int> q;
    vector<int> ans;

    for(int i=0;i<k;i++){
        while(!q.empty() && v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);

    for(int i=k;i<n;i++){                        

        if(q.front() == i- k){
            q.pop_front();
        }
        while(!q.empty() && v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(v[q.front()]);
    }
    return ans;
}


int main(){
  
  vector<int> v = maxInWindow({1,2,3,1,4,5,2,3,6},3);
  for(auto i : v){
      cout<<i<<" ";
  }
  return 0;
}
