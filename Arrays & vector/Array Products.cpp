#include<bits/stdc++.h>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    vector<int> left(n);
    vector<int> right(n);
    
    left[0] = 1;
    right[n-1] = 1;
    
    for(int i=1;i<n;i++){
        left[i] = left[i-1] * arr[i-1];
    }
    
    for(int i =n-2;i>=0;i--){
        right[i] = right[i+1] * arr[i+1];
    }
    for(int i=0;i<n;i++){
        output[i] = right[i]*left[i];
    }
    return output;
}
int main(){
  
  vector<int> v = {1,2,3,4,5};
  v = productArray(v);
  for(auto i : v){
     cout<<i<<" ";
  }
  return 0;
}
