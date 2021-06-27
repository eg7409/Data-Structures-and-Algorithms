#include<bits/stdc++.h>
using namespace std;

//Housing Implementation + smallest window

vector<pair<int,int> > sliding(vector<int> v,int target){
  int n = v.size();
  vector<pair<int,int> > p;

  int i=0,j=0;
  int sum = 0;

  while(j<n){
    sum += v[j];
    j++;

    while(sum>target && i<j){
      sum -= v[i];
      i++;
    }
    if(sum == target){
      p.push_back({i,j-1});
    }
  }
  return p;
}

int main(){
  
  vector<pair<int,int> > v = sliding({1,3,2,1,4,1,3,2,1,1},8);
  
  int f=0,s=0,mini=INT_MAX;

  for(auto i : v){
    if(mini>i.second-i.first){
      mini = i.second-i.first;
      f = i.first;
      s = i.second;
    }
  }
  cout<<f<<" "<<s<<endl;
  return 0;
}
