#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Min Array Jumps

int solve(vector<int> v,int n,int i,vector<int> dp){
    if(i == n-1){
        return 0;
    }

    if(i>=n){
        return INT_MAX;
    }

    if(dp[i]!=0){
        return dp[i];
    }

    int jumps = v[i];
    int steps = INT_MAX;

    for(int jump = 1;jump<=jumps;jump++){
        int next = i+jump;
        int sub = solve(v,n,next,dp);
        if(sub!=INT_MAX){
            steps = min(steps,sub+1);
        }
        
    }

    dp[i] = steps;

    return dp[i];
}

int main(){

    vector<int> v = {3,4,2,1,2,3,7,1,1,3};

    int n = v.size();

    vector<int> dp(n,0);

    
    cout<<solve(v,n,0,dp);
    return 0;
}
