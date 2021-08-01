#include <bits/stdc++.h>
using namespace std;

//First Non-repeating Letter

void solve(string s){
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
            cout<<-1<<" ";
        }
        else{
            cout<<q.front()<<" ";
        }
    }
    
    cout<<endl;
}

int main(){

    string s = "aabccbcd";
    solve(s);
    return 0;
}


