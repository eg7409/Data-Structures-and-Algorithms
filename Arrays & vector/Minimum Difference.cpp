#include <bits/stdc++.h>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    
    
    int n = a.size();
    int m = b.size();
    
    int diff = INT_MAX;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0,j = 0;
     int f=0,s=0;
    while(i!=n && j!=m){
        if(abs(a[i]-b[j]) < diff){
                diff = abs(a[i]-b[j]);
                f = a[i];
                s = b[j];
        }
        if(a[i]>b[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return {f,s};
    
    
    
}
int main(){

    vector<int> v1 = {23,5,10,17,30};
    vector<int> v2 = {26,134,135,14,19};
    cout<<minDifference(v1,v2).first<<" "<<minDifference(v1,v2).second<<endl;
    
	return 0;
}
