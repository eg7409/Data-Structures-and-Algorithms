#include<bits/stdc++.h>
using namespace std;

//Quick Select

int partition(vector<int> &v,int start,int end){
    int i = start-1;
    int pivot = v[end];

    for(int j = start;j<=end;j++){
        if(v[j] < pivot){
            i++;
            swap(v[i],v[j]);
        }
    }

    swap(v[i+1],v[end]);
    return i+1;
}

int quickselect(vector<int> &v,int start,int end,int k){
    
    int p = partition(v,start,end);

    if(p == k){
        return v[p];
    }
    else if(k < p){
        return quickselect(v,start,p-1,k);
    }
    else{
        return quickselect(v,p+1,end,k);
    }
}
int main(){
 
  vector<int> v = {1,5,6,3,2,6,9,0,7,5};
  cout<<quickselect(v,0,v.size()-1,3);
  
  
  return 0;
}
