#include<bits/stdc++.h>
using namespace std;

int fun(string a,string b){
    string ab = a.append(b);
    string ba = b.append(a);
    
    return ab.compare(ba)>0?1:0;
}

string concatenate(vector<int> v){
    //complete this method and return the largest number you can form as a string
    
    vector<string> s;
    string ans = "";
    int n = v.size();
    
    int zero=0;
    
    for(int i=0;i<n;i++){
        if(v[i] == 0){
            zero++;
        }
        else{
            s.push_back(to_string(v[i]));
        }
    }
    if(zero == n){
        return "0";
    }
    sort(s.begin(),s.end(),fun);
    
    for(auto i :s){
        ans += i;
    }
    return ans;
}
