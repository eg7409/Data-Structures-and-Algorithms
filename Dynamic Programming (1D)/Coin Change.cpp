#include <bits/stdc++.h>
using namespace std;

//Coin Change

void solve(int target,vector<int> v){

    int n = v.size();

    vector<int> dp(target+1,0);

    dp[0] = 0;

    for(int i=1;i<=target;i++){
        dp[i] = INT_MAX;
        for(int c : v){
            if(i-c>=0 && dp[i-c]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
    }
    if(dp[target]==INT_MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<dp[target]<<endl;
}

int main(){

    int target = 8;
    vector<int> v = {1,5,7,10};

    solve(target,v);
    return 0;
}
