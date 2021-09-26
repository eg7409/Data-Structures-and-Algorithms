#include<bits/stdc++.h>
using namespace std;

long long minimumCost(vector<int> h, int k){
    //Write your code here. Do not modify the function or the parameters. Use a helper function if needed
    
   
    int n = h.size(); 
    vector<long long> dp(n,LONG_MAX);
    
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    
    for(int i=2;i<n;i++){
        
        for(int j=1;j<=k&&i-j>=0;j++){
            dp[i] = min(dp[i],dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    return dp[n-1];
}
