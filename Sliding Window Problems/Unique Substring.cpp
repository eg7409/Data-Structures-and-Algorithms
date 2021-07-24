#include<bits/stdc++.h>
using namespace std;

//Unique Substring

pair<int,int> substring(string s){

  map<char,int> m;
  int n = s.length();

  int i=0,j=0;
  int maxi=INT_MIN;

  int c = 0;
  int ind1 =-1;
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
       
    }
  }

  return {ind1,maxi};
}


int main(){
  string s = "abcabed";
  pair<int,int> p = substring(s);

  for(int i=p.first;i<=p.second;i++){
    cout<<s[i];
  }
  return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;


pair<int,int>  solve(string s){
    int n = s.length();

    int i=0,j=0,c=0,maximum=INT_MIN;

    map<char,int> m;
    int first =-1,second=-1;

    while(j<n){

        if(m.find(s[j]) != m.end()){
            if(m[s[j]] >= i){
                c=1;
                m[s[j]] = j;
                i = j;
                j++;
                
            }
            else{
                m[s[j]] = j;
                j++;
                c++;
            }
        }
        else{
            c++;
            m[s[j]] = j;
            j++;
        }

        if(maximum < c){
            maximum = c;
            first = i;
            second = j;
        }

    }
    
    return {first,second};
}


int main(){

    string s = "prateekbhaiya";
   pair<int,int> p = solve(s);

   for(int i=p.first;i<p.second;i++){
       cout<<s[i];
   }
    return 0;
}


*/
