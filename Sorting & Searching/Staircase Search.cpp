#include<bits/stdc++.h>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
    
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == k){
                return {i,j};
            }
        }
    }
    return {-1,-1};*/
    
  
    int index = -1;
    
    for(int i=0;i<n;i++){
        if(v[0][i] == k){
            return {0,i};
        }
        if(v[0][i] < k){
            index = i;
        }
    }
    for(int i=0;i<m;i++){
        if(v[i][index] == k){
            return {i,index};
        }
    }
    return {-1,-1};

}
