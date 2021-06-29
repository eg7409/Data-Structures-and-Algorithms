#include<bits/stdc++.h>
using namespace std;


int merge(vector<int> &v,int start,int end){
    int i= start,m = start + (end-start)/2, j=m+1;

    vector<int> temp;
    int count = 0;

    while(i<=m && j<=end){
        if(v[i] < v[j]){
            temp.push_back(v[i++]);
        }
        else{
            temp.push_back(v[j++]);
            count += (m-i+1);
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
    return count;
}

int inversion(vector<int> &v,int start,int end){
    if(start >= end){
        return 0;
    }

    int mid = start + (end-start)/2;
    int c1 = inversion(v,start,mid);
    int c2 = inversion(v,mid+1,end);

    int c3 = merge(v,start,end);

    return c1+c2+c3;
}




int main(){
  
  vector<int> v = {0,5,2,3,1};
 cout<<inversion(v,0,v.size()-1);
  return 0;
}
