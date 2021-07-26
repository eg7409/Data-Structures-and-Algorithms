#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v,int i){
    
    if(i == 0){
        return v[i] > v[1];
    }
    
    if(i == v.size()-1){
        return v[i] < v[v.size() - 2];
    }
    
    return v[i] < v[i-1] || v[i] > v[i+1]; 
}

pair<int,int> subarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    
    int n = a.size();
    int smallest = INT_MAX,largest = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(check(a,i)){
            smallest = min(smallest,a[i]);
            largest = max(largest,a[i]);
        }
    }
    
    if(smallest == INT_MAX){
        return {-1,-1};
    }
    
    int left = 0;
    
    while(smallest >= a[left]){
        left++;
    }
    
    int right = n-1;
    
    while(largest <= a[right]){
        right--;
    }
    return {left,right};
}

