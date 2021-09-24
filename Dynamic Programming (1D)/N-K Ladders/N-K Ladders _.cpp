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

void countWays1(int n,int k){

    vector<int> dp(n+1,0);
    dp[0] = 1;


    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=k;j++){
            if(i - j >= 0){
                dp[i] += dp[i-j];
            }
        }
    }

    cout<<dp[n]<<endl;
}

void solve(int n,int k){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=k;i++){
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[n-k-1];
    }

    cout<<dp[n]<<endl;
}


int main(){

    int n,k;
    cin>>n>>k;

    vector<int> dp(n+1,0);

    cout<<countWays(n,k,dp);
    countWays1(6,4);
    solve(6,4);

    return 0;
}
