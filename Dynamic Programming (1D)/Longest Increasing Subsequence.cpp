#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Longest Increasing Subsequence

int solve(vector<int> v,int n){
    vector<int> dp(n,1);

    int len = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i] > v[j]){
                dp[i] = max(dp[i],dp[j]+1);
                len = max(len,dp[i]);
            }
        }
    }
    return len;
}

int main(){

    vector<int> v = {50,4,10,8,30,100};
    int n = v.size();

    cout<<solve(v,n)<<endl;
    
    return 0;
}
