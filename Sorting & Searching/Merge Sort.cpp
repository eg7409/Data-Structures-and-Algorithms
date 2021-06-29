#include<bits/stdc++.h>
using namespace std;
//Merge Sort

void merge(vector<int> &v,int start,int end){
    int i= start,m = start + (end-start)/2, j=m+1;

    vector<int> temp;

    while(i<=m && j<=end){
        if(v[i] < v[j]){
            temp.push_back(v[i++]);
        }
        else{
            temp.push_back(v[j++]);
        }
    }

    while(i <= m){
        temp.push_back(v[i++]);
    }
    while(j <= end){
        temp.push_back(v[j++]);
    }

    int k = 0;
    for(int in = start;in<=end;in++){
        v[in] = temp[k++];
    }
    return;
}

void mergesort(vector<int> &v,int start,int end){
    if(start >= end){
        return;
    }

    int mid = start + (end-start)/2;
    mergesort(v,start,mid);
    mergesort(v,mid+1,end);

    return merge(v,start,end);
}




int main(){
  
  vector<int> v = {8,4,2,1,4,6,5,3,2,4,4};
  mergesort(v,0,v.size());
//   for(auto i : v){
//       cout<<i<<" ";
//   }
//   cout<<endl;
  vector<int>::iterator it = v.begin();

  while(it!=v.end()){
      cout<< *it<<" ";
      it++;
  }
  return 0;
}
