#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v,int n,int k,int mid){
    
    int sum = 0;
    int fr = 0;
    for(int i=0;i<n;i++){
        if(sum + v[i]>=mid){
            fr++;
            sum = 0;
        }
        else{
            sum += v[i];
        }
    }
    return fr >= k;
}

int getCoins(vector<int> v, int k){
    //return the max coins that you can win!
    
    int sum=0,n = v.size();
    for(int i =0;i<n;i++){
        sum+=v[i];
    }
    
    int start = 0,end = sum;
    int ans = 0;
    
    while(start <= end){
        int mid = start + ((end - start)/2);
        
        if(check(v,n,k,mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
