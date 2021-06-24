#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> v,int target){
    

    int n = v.size();
    sort(v.begin(),v.end()); 
    vector<vector<int>> result;
    int sum = 0;
    
    for(int i=0;i<n-2;i++){
        int j = i+1, k =n-1;
        while(j<k){
            sum = v[i] + v[j] + v[k];

            if(sum == target){
                result.push_back({v[i],v[j],v[k]});
                j++;
                k--;
            }
            else if(sum > target){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return result;
}

int main(){

	vector<int> v = {1,2,3,4,5,6,-1,-4,-3};
    int target = 7;

    vector<vector<int>> ans = triplets(v,target);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
	
	return 0;
}
