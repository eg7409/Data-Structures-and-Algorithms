#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
  
 
  string comp = "";
  int c = 1;
  int lastIndex = 0;
  
  for(int i=1;i<str.length();i++){
      if(str[i-1] == str[i]){
          c++;
      }
      else{
          comp += str[i-1] + to_string(c);
          c = 1;
      }
  }

  comp += str[str.length()-1] + to_string(c);

  if(str.length()<comp.length()){
      return str;
  }
  return comp;
}
