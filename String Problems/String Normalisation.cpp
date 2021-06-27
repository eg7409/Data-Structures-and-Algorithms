#include<bits/stdc++.h>
using namespace std;



string normalize(const string &c) {
    string s = c;
    //Make the changes in copy, and return it

    bool f = true;
    int n = c.length();

    for(int i =0;i<n;i++){
      if(s[i] == ' '){
        f = true;
      }
      else if(f){
        s[i] = toupper(s[i]);
        f = false;
      }
      else{
        s[i] = tolower(s[i]);
      }
    }

    return s;
}

int main(){

    cout<<normalize("This is SO MUCH FUN!");
  return 0;
}
