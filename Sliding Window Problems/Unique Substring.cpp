#include<bits/stdc++.h>
using namespace std;

//Unique Substring

pair<int,int> substring(string s){

  map<char,int> m;
  int n = s.length();

  int i=0,j=0;
  int maxi=INT_MIN;

  int c = 0;
  int ind1 =-1,ind2=-1;
  while(j<n){
    if(m.find(s[j]) != m.end() && m[s[j]]>=i){       // greater than start of the window

      i = m[s[j]] + 1;
      c=j-i; // c = j-1-(i-1) + "1"-> added later
    }
    
    m[s[j]] = j;
    j++;
    c++;
    
    if(maxi <= c){
        maxi = c;
        ind1 = i;
        ind2 = j-1;
    }
  }

  return {ind1,ind2};
}


int main(){
  string s = "abcabed";
  pair<int,int> p = substring(s);

  for(int i=p.first;i<=p.second;i++){
    cout<<s[i];
  }
  return 0;
}
