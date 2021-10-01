#include<bits/stdc++.h>
using namespace std;


void f(string s,vector<string> &v,int l,int r){
    if(l==r){
        v.push_back(s);
        return;
    }
    
    for(int i =l;i<=r;i++){
        swap(s[i],s[l]);
        f(s,v,l+1,r);
        swap(s[i],s[l]);
    }
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    vector<string> v;
    f(s,v,0,s.length()-1);
    
    set<string> se;
    
    for(auto i:v){
        se.insert(i);
    }
    v.clear();
    
    auto it = se.begin();
    
    while(it!=se.end()){
        v.push_back(*it);
        it++;
    }
    
    return v;
}
