#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Knapsack Problem

int recursive(vector<int> weight,vector<int> price,int totalWeight,int n){
    if(n==0||totalWeight==0){
        return 0;
    }

    int inc,exc;
    if(totalWeight - weight[n-1] >= 0){
        inc = price[n-1] + recursive(weight,price,totalWeight - weight[n-1],n-1);
    }
    exc = recursive(weight,price,totalWeight,n-1);

    return max(inc,exc);
}

int bottomUp(vector<int> weight,vector<int> price,int totalWeight,int n){

    vector<vector<int> > dp(n+1,vector<int> (totalWeight+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=totalWeight;j++){
            int inc = 0,exc=0;
            if(j-weight[i-1] >= 0){
                inc = price[i-1] + dp[i-1][j-weight[i-1]];
            }
            exc = dp[i-1][j];

            dp[i][j] = max(inc,exc);
        }
    }
    return dp[n][totalWeight];
}


int main(){

    vector<int> weight = {2,7,3,4};
    vector<int> price = {5,20,20,10};

    int n = weight.size();
    int totalWeight = 11;

    cout<<recursive(weight,price,totalWeight,n)<<endl;
    cout<<bottomUp(weight,price,totalWeight,n)<<endl;

    return 0;
}
