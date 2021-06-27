#include<bits/stdc++.h>
using namespace std;

//sort subsequence

void subsequence(string s,string o,vector<string> &v){

  if(s.size() == 0){
    v.push_back(o);
    return;
  }

  subsequence(s.substr(1),o+s[0],v);
  subsequence(s.substr(1),o,v);

}

bool sorting(string a,string b){
  if(a.length() == b.length()){
    return a < b;
  }
  return a.length() < b.length();
}
int main(){
  string o = "";
  vector<string> v;
  string s = "abcd";

  subsequence(s,o,v);
  sort(v.begin(),v.end(),sorting);

  for(auto i : v){
    cout<<"["<<i<<"]";
  }
  cout<<endl;
  return 0;
}
