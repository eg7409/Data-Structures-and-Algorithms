#include<bits/stdc++.h>
using namespace std;



int cntSubarrays(vector<int> v,int k){
    //complete this method
    
      map<int,int> m;

  int n = v.size();
  int sum = 0;
  int count = 0;
  m[0]++;
  for(int i=0;i<n;i++){
      sum += v[i];

      if(m.find(sum - k) != m.end()){
          count += (m[sum-k]);
      }
      m[sum]++;
  }
  return count;
}
