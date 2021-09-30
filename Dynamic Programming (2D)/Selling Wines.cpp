#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Selling Wines

int recursive(vector<int> v,int l,int r,int y){
    if(l>r){
        return 0;
    }

    int op1 = y*v[l] + recursive(v,l+1,r,y+1);
    int op2 = y*(v[r]) + recursive(v,l,r-1,y+1);

    return max(op1,op2);
}

int topDown(vector<int> v,int l,int r,int y,vector<vector<int> > &dp){
    if( l > r){
        return 0;
    }

    if(dp[l][r]!=0){
        return dp[l][r];
    }

    int op1 = y*v[l] + topDown(v,l+1,r,y+1,dp);
    int op2 = y*v[r] + topDown(v,l,r-1,y+1,dp);

    return dp[l][r] = max(op1,op2);
}

int bottomUp(vector<int> v,int n){
    vector<vector<int> > dp(n,vector<int>(n,0));

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i == j){
                dp[i][j] = n * v[i];
            }
            else if(i<=j){
                int y = n - (j-i);

                dp[i][j] = max(y*v[i] + dp[i+1][j],y*v[j]+dp[i][j-1]);
            }
        }
    }

    for(auto i : dp){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int main(){

    vector<int> v = {2,3,5,1,4};
    int n = v.size();

    vector<vector<int> > dp(n,vector<int>(n,0));

    cout<<recursive(v,0,n-1,1)<<endl;
    cout<<topDown(v,0,n-1,1,dp)<<endl;
    cout<<bottomUp(v,n)<<endl;

    for(auto i : dp){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }    
    return 0;
}
