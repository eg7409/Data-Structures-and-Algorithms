#include<bits/stdc++.h>
using namespace std;

//Smallest String


bool here(string a,string b){

    string s1 = a.append(b);
    string s2 = b.append(a);

    return s1 < s2;
}
void smallestString(vector<string> v){

    sort(v.begin(),v.end(),here);

    for(auto i :v){
        cout<<i;
    }
}
int main(){
 
  vector<string> v = {"c","cb","cba"};
  smallestString(v);
  
  return 0;
}
