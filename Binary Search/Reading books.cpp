#include<bits/stdc++.h>
using namespace std;


bool check(vector<int> v,int mid,int n,int s){
    int students = 1;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        if(sum + v[i] > mid){
            sum = v[i];
            students++;
        }
        else{
            sum += v[i];
        }
    }
    return students<=s;
}

int minPages(vector<int> v, int s){
  int sum = 0;
  int maxi = 0;
  int n = v.size();
  
  
  for(int i=0;i<n;i++){
      sum += v[i];
      maxi = max(maxi,v[i]);
  }
  
  int start = maxi,end = sum;
  int ans = 0;
  
  while(start <= end){
      int mid = start + ((end - start)/2);
      
      if(check(v,mid,n,s)){
          ans = mid;
          end = mid - 1;
      }
      else{
          start = mid + 1;
      }
  }
  return ans;
}
