#include <bits/stdc++.h>
using namespace std;


//Subset sum to X

int subsetssum(vector<int> v,int n,int i,int total){

    if(i == n){
        if(total == 0){
            return 1;
        }
        return 0;
    }

    int inc = subsetssum(v,n,i+1,total - v[i]);
    int exc = subsetssum(v,n,i+1,total);

    return inc + exc;

}

int main(){
   
    vector<int> v = {1,2,3,4,5};

    int sum = 10;

    cout<<subsetssum(v,v.size(),0,sum);
    return 0;
}
