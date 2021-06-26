#include<bits/stdc++.h>
using namespace std;

string space20(string s){
  int space = 0;

  for(int i=0;i<s.length();i++){
    if(s[i] == ' '){
      space++;
    }
  }
  int req = space*2;
  for(int i=0;i<req;i++){
    s.push_back(0);
  }
  for(int i=s.length()-1;i>=0;i--){
    if(s[i] != ' '){
      s[i+req] = s[i];
    }
    else{
      s[i+req] = '0';
      s[i+req-1] = '2';
      s[i+req-2] = '%';
      req-=2;
    }
  }
  return s;
}
int main(){
    cout<<space20("Hello There, My name is Eishita Gupta");
  return 0;
}
