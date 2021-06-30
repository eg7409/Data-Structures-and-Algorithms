#include<bits/stdc++.h>
using namespace std;

//Rotated Search
//Position of an element via modified binary search


int rotated(vector<int> v,int start,int end,int key){

    while(start<=end){
        int mid = start + ((end-start)/2);

        if(v[mid] == key){
            return mid;
        }

        if(v[start] <= v[mid]){
            if(v[start] <= key && key <= v[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            if(v[mid] <= key && v[end] >= key){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    

    vector<int> v = {5,6,7,8,9,1,2,3,4};
    cout<<rotated(v,0,v.size()-1,3);
  return 0;
}
