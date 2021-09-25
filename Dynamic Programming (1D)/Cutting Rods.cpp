#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Cutting Rods

int solve(vector<int> prices,int n){

    if(n<=0){
        return 0;
    }

    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int cut = i+1;

        int curr = prices[i] + solve(prices,n-cut);
        ans = max(ans,curr);
    }
    return ans;
}

int solve(int n,vector<int> prices){
    if(n==0){
        return 0;
    }

    vector<int> dp(n+1);
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        int ans = INT_MIN;

        for(int j = 0;j<i;j++){
            int cut = j+1;

            int curr = prices[j] + dp[i-cut];
            ans = max(ans,curr);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main(){

    vector<int> prices = {3,5,8,9,10,17,17,20};
    int n = prices.size();

    cout<<solve(prices,n)<<endl;
    cout<<solve(n,prices)<<endl;

    return 0;
}
