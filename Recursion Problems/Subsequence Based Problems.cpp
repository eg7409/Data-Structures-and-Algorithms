#include <bits/stdc++.h>
using namespace std;

//Finding Subsets

void solve(string s,string s1,vector<string> &v){

    if(s.length() == 0){
        v.push_back(s1);
        return;
    }
    
    char f = s[0];
    s = s.substr(1);
    solve(s,s1+f,v);
    solve(s,s1,v);

}

bool here(string a,string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }

    return a < b;    
}
int main(){
   
    string s = "abc";
    string s1 = "";
    vector<string> v;
    solve(s,s1,v);
    sort(v.begin(),v.end(),here);
    for(auto i : v){
        cout<<"["<<i<<"] ,";
    }
    return 0;
}
