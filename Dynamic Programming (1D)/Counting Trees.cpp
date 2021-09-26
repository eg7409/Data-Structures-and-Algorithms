#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Counting Trees

int recursive(int n){
    if(n==0 || n==1){
        return 1;
    }

    int ans = 0;

    for(int i=1;i<=n;i++){
        int x = recursive(i-1);
        int y = recursive(n-i);

        ans += x*y; 
    }

    return ans;
}

int topDown(int n,vector<int> dp){
    if(n == 0 || n == 1){
        return 1;
    }

    if(dp[n]!=0){
        return dp[n];
    }

    int ans = 0;

    for(int i=1;i<=n;i++){
        int x = topDown(i-1,dp);
        int y = topDown(n-i,dp);

        ans += x*y;
    }

    dp[n] = ans;

    return dp[n];
}

int bottomUp(int n,vector<int> dp){

    if(n == 0|| n==1){
        return 1;
    }

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

int main(){

    int n=5;

    vector<int> v(n+1,0);

    cout<<recursive(n)<<endl;

    cout<<topDown(n,v)<<endl;

    cout<<bottomUp(n,v)<<endl;

    
    return 0;
}
