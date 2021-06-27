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




// STORING ONLY ONE VALUE IN VECTOR
#include<bits/stdc++.h>
using namespace std;

//Housing Implementation + smallest window

vector<pair<int,int> > sliding(vector<int> v,int target){
  int n = v.size();
  vector<pair<int,int> > p;

  int i=0,j=0;
  int sum = 0;
  int f=0,s=0,find = INT_MAX;

  while(j<n){
    sum += v[j];
    j++;

    while(sum>target && i<j){
      sum -= v[i];
      i++;
    }
    if(sum == target){
      if(find>j-1-i){
        find = j-1-i;
        f = i;
        s = j-1;
      }
      
    }
  }
  p.push_back({f,s});
  return p;
}

int main(){
  
  vector<pair<int,int> > v = sliding({1,3,2,1,4,1,3,2,1,1},8);
  

  for(auto i : v){
    cout<<i.first<<" "<<i.second<<endl;
  }
  
  return 0;
}
