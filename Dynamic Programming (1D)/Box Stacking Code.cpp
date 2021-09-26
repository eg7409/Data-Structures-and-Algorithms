#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Box Stacking Code

bool comp(vector<int> a,vector<int> b){
    return a[2] < b[2];
}

bool check(vector<int> a,vector<int> b){
    if( a[0]>b[0] && a[1]>b[1] && a[2]>b[2]){
        return true;
    }
    return false;
}

int solve(vector<vector<int> > v,int n){

    sort(v.begin(),v.end(),comp);

    for(auto i : v){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int> dp(n+1,0);

    for(int i=0;i<n;i++){
        dp[i] = v[i][2];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(check(v[i],v[j])){
                dp[i] = max(dp[i],v[i][2] + dp[j]);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }

    return ans;
}

int main(){

    vector<vector<int> > v = {{2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}};
    int n = v.size();

    cout<<solve(v,n)<<endl;
    
    return 0;
}
