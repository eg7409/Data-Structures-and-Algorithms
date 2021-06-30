#include<bits/stdc++.h>
using namespace std;


//First Occurence

int start(vector<int> v,int start,int end,int k){
    int index = -1;
    while(start<=end){
        int mid = start + ((end-start)/2);
        if(v[mid] >= k){
            end = mid - 1;
        }
        else{
            start = mid +1;
        }
        if(v[mid] == k){
            index = mid;
        }
    }
    return index;
}

//Last Occurence

int end(vector<int> v,int start,int end,int k){
    int index = -1;
    while(start<=end){
        int mid = start + ((end - start)/2);

        if(v[mid] <= k){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        if(v[mid] == k){
            index = mid;
        }
    }
    return index;
}
int main(){
    vector<int> v = {0,1,1,2,3,3,3,3,4,5,5,5,10}; 
    int n = v.size();

    cout<<(end(v,0,n-1,3) - start(v,0,n-1,3) + 1)<<endl;                                    //Binary Search
    cout<<upper_bound(v.begin(),v.end(),3) - lower_bound(v.begin(),v.end(),3);             //Using STL
  return 0;
}
