#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Frog's Min Cost - I

//Bottom up
int solve(vector<int> h,int n){
    vector<int> dp(n,0);

    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    return dp[n-1];
}

int main(){

    vector<int> v = {10,30,40,20};

    int n = v.size();
    
    cout<<solve(v,n);
    return 0;
}
