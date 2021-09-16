#include <bits/stdc++.h>
using namespace std;


// O(n*k)
int countWays(int n,int k,vector<int> dp){
    
    if(n==0){
        return 1;
    }

    if(n < 0){
        return 0;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int ans = 0;

    for(int i=1;i<=k;i++){
        ans += countWays(n-i,k,dp);
    }

    dp[n] = ans;

    return dp[n];

}

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> dp(n+1,0);

    cout<<countWays(n,k,dp);

    return 0;
}
