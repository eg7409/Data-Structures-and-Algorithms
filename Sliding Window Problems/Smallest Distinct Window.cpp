#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string s){
    //Complete this method
    
    map<char,int> m;
    int i=0,j=0;
    
    int n = s.length();
    int c = 0;
    int index = 0;
    int maxi=INT_MIN;
    
    while(j<n){
        
        if(m.find(s[j])!=m.end()&& m[s[j]] >= i){
            i = m[s[j]] + 1;
            c = j-i;   
        }
        
        m[s[j]] = j;
        j++;
        c++;
        
        if(maxi <= c){
            maxi = c;
            index = i;
        }
    }
    return s.substr(index,maxi);
}
