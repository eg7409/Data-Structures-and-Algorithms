#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Counting Subsequence

int recursive(string s1,string s2,int i,int j){
    if(i==-1 && j==-1 || j==-1){
        return 1;
    }
    if(i==-1){
        return 0;
    }

    if(s1[i] == s2[j]){
        return recursive(s1,s2,i-1,j-1) + recursive(s1,s2,i-1,j);
    }

    return recursive(s1,s2,i-1,j);
}

int bottomUp(string s1,string s2){

    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){

    string s1 = "ABBCECDGCC";
    string s2 = "ABC";

    cout<<recursive(s1,s2,s1.size()-1,s2.size()-1)<<endl;
    cout<<bottomUp(s1,s2)<<endl;
    return 0;
}
