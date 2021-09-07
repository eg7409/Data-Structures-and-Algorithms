#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string s){
    
    map<char,int> m;
    
    int n = s.length();
    
    for(int i=0;i<n;i++){
        if(m.find(s[i])==m.end()){
            m[s[i]] = i;
        }
        else{
            return s[i];
        }
    }
    
    return s[n-1];
    
}
