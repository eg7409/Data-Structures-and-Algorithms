#include <bits/stdc++.h>
using namespace std;


//Generate Brackets

void solve(string output,int open,int close,int i,int n){
    if(i == 2*n){
        cout<< output<<endl;
        return;
    }

    if(open < n){
        solve(output+'(',open+1,close,i+1,n);
    }
    if(close < open){
        solve(output+')',open,close+1,i+1,n);
    }
}

int main(){
   
    string output = "";
    solve(output,0,0,0,3);
    return 0;
}
