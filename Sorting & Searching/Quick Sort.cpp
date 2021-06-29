#include<bits/stdc++.h>
using namespace std;

//Quick Sort

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

void quicksort(vector<int> &v,int start,int end){
    if(start >= end){
        return;
    }
    
    int p = partition(v,start,end);

    quicksort(v,start,p-1);
    quicksort(v,p+1,end);
}
int main(){
 
  vector<int> v = {1,5,6,3,2,6,9,0,7,5};
  quicksort(v,0,v.size()-1);
  
  for(auto i : v){
      cout<<i<<" ";
  }
  return 0;
}
