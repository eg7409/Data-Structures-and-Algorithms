#include<vector>
using namespace std;

int partition(vector<int> &v,int start,int end){
    
    int pivot = v[end];
    int mid = start + ((end - start)/2);
    int i = start - 1;
    
    for(int j = start;j <= end; j++){
        if(v[j] < pivot){
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



vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)

      
    quicksort(balls,0,balls.size()-1);
    
    return balls;
}
