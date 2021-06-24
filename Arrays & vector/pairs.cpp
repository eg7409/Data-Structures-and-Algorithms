#include <bits/stdc++.h>
using namespace std;

vector<int> pairs(vector<int> v,int target){
    int n = v.size();

    set<int> s;
    int c = 0;

    for(int i =0;i<n;i++){
        c = target - v[i];

        if(s.find(c) != s.end()){
            return {v[i],c};
        }

        s.insert(v[i]);
    }

    return {};
}

int main(){

	vector<int> v = {1,2,3,4,5,6,3,2,-1,-3,5-4,-3};
    int target = 7;

    vector<int> m = pairs(v,target);
    for(auto i : m ){
        cout<<i<<" ";
    }
    cout<<endl;
	
	return 0;
}
