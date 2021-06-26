#include<bits/stdc++.h>
using namespace std;

//tokenisation using string streams

int main(){
    
    string s;
    getline(cin,s);
    stringstream ss(s);

    string token;
    vector<string> tokens;

    while(getline(ss,token,' ')){  // stringstream , token , delimiter
      tokens.push_back(token);
    }

    for(auto i : tokens){
      cout<< i << ",";
    }
    cout<<endl;

  return 0;
}
