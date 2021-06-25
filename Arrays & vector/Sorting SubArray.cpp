#include <bits/stdc++.h>
using namespace std;


//sorting subarray

bool check(vector<int> v,int x){
    int a = v[x];

    if(x==0){
        return a > v[1]; 
    }
    else if(x==v.size()-1){
        return a < v[v.size()-2];
    }
    else{
        return a < v[x-1] || a > v[x+1];
    }
}

pair<int,int> subArray(vector<int> v){

    int n = v.size();
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i =0;i<n;i++){
        if(check(v,i)){
            smallest = min(smallest,v[i]);
            largest = max(largest,v[i]);
        }
    }
    if(smallest == INT_MAX){
        return {-1,-1};
    }
    
    int left = 0;
    while(smallest >= v[left]){
        left++;
    }
    int right = n-1;
    while(largest <= v[right]){
        right--;
    }

    return {left,right};
}
int main(){

    vector<int> v = {1,2,3,4,5,8,6,9,7,10,11};
    auto p = subArray(v);
    cout<<p.first<<" "<<p.second<<endl;   
	return 0;
}
