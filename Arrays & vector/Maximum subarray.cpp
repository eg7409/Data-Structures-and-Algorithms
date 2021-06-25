#include<vector>
using namespace std;

int maxSubarraySum(vector<int> v){
    //Complete this function, your function should return the maximum subarray sum
    int n = v.size();
    
    int index = -1;
    
    for(int i=0;i<n;i++){
        if(v[i]>0){
            index = i;
            break;
        }
    }
    if(index == -1){
        return 0;
    }
    int sum=0,maxSum=0;
    
    for(int i=index;i<n;i++){
        sum+=v[i];
        if(sum<0){
            sum=0;
        }
        maxSum = max(sum,maxSum);
    }
    return maxSum;
    
}
int main(){
  vector<int> v ={-1,2,3,4,-2,6,-8,3};
  cout<< maxSubarraySum(v)<<endl;
  return 0;
}
