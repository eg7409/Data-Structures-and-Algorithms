#include <bits/stdc++.h>
using namespace std;


//trapping rain water

int rain(vector<int> v){

    int n = v.size();

    vector<int> left(n);
    vector<int> right(n);
    int maxi = 0;

    for(int i=0;i<n;i++){
        maxi = max(v[i],maxi);
        left[i] = maxi;
    }
    maxi=0;
    for(int i=n-1;i>=0;i--){
        maxi = max(v[i],maxi);
        right[i] = maxi;
    }
    vector<int> water(n);

    for(int i=0;i<n;i++){
        water[i] = min(left[i],right[i]) - v[i];
    }
    int res=0;
    for(auto i :water){
        res += i;
    }
    return res;
}
int main(){

   vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<rain(v)<<endl;
   
	return 0;
}
