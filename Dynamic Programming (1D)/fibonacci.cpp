#include <bits/stdc++.h>
using namespace std;

int main(){

    int n = 9;
    vector<int> dp(n+1,0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(auto i : dp){
        cout<<i<<" ";
    }

    return 0;
}


/*

Output:

0 1 1 2 3 5 8 13 21 34 

*/
