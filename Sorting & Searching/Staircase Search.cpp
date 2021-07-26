#include<bits/stdc++.h>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == k){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
