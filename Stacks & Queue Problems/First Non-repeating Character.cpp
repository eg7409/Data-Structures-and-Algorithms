#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string s){
    vector<char> ans;
    map<char,int> m;
    queue<char> q;

    int n = s.length();

    for(int i=0;i<n;i++){
        m[s[i]]++;
        q.push(s[i]);

        while(!q.empty() && m[q.front()] > 1){
            q.pop();
        }
        if(q.empty()){
            ans.push_back('0');
          
        }
        else{
           
           ans.push_back(q.front());
        }
    }
    return ans;
}
