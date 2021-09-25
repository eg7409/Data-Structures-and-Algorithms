#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Maximum Non Adjacent Sum

int solve(vector<int> v,int n){
    int with=v[0],without=0;

    for(int i=1;i<n;i++){
        int t = with;
        with = (without + v[i]);
        without = max(without,t);
    }
    return max(with,without);
}

int check(vector<int> v,int n){
    vector<int> dp(n,0);

    if(n==1){
        return max(0,v[0]);
    }
    dp[0] = v[0];
    dp[1] = max(dp[0],v[1]);

    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1] , dp[i-2]+v[i]);
    }

    return dp[n-1];
}
int main(){

    vector<int> v = {6,10,12,7,9,14};
    int n = v.size();

    cout<<solve(v,n)<<endl;
    cout<<check(v,n)<<endl;
    return 0;
}
