#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Longest Common Subsequence

int recursive(string s1,string s2,int i,int j){

    if(i == s1.length() || j == s2.length()){
        return 0;
    }

    if(s1[i] == s2[j]){
        return 1 + recursive(s1,s2,i+1,j+1);
    }

    int op1 = recursive(s1,s2,i+1,j);
    int op2 = recursive(s1,s2,i,j+1);

    return max(op1,op2);
}

int topDown(string s1,string s2,int i,int j,vector<vector<int> > &dp){

    if(i == s1.length() || j == s2.length()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + topDown(s1,s2,i+1,j+1,dp);
    }

    int op1 = topDown(s1,s2,i+1,j,dp);
    int op2 = topDown(s1,s2,i,j+1,dp);

    return dp[i][j] = max(op1,op2);
}

int bottomUp(string s1,string s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int> > dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }


    int i=n,j=m;

    vector<char> res;
    while(i!=0 && j!=0){
        if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
    }

    reverse(res.begin(),res.end());

    for(auto i : res){
        cout<<i;
    }
    cout<<endl;
    return dp[n][m];
}

int main(){

    string s1 = "ABCD" , s2 = "ABEDG";

    cout<<recursive(s1,s2,0,0)<<endl;
    int n = s1.length();
    int m = s2.length();

    vector<vector<int> > dp (n,vector<int>(m,-1));
    cout<<topDown(s1,s2,0,0,dp)<<endl;
    cout<<bottomUp(s1,s2)<<endl;
    
    return 0;
}
