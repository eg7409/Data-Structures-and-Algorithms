#include <bits/stdc++.h>
using namespace std;

//Check Subsets

bool check(string a,string b){
  int i=0,j=0;

  int n = a.length(),m = b.length();

  while(i<n && j<m){
    if(a[i] == b[j]){
      i++;
      j++;
    }
    else{
      i++;
    }
  }
  if(j != m){
    return false;
  }
  return true;
}
int main(){

  cout<<check("codingminutes","cines"); 
  return 0;
}
