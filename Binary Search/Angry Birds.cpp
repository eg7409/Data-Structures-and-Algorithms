#include<bits/stdc++.h>
using namespace std;

//Angry Birds

bool checkPositions(vector<int> v,int n,int b,int mid){
    int birds = 1;

    int location = v[0];
    int currentLocation = 0;

    for(int i=1;i<=n-1;i++){
        currentLocation = v[i];

        if(currentLocation - location >= mid){
            birds++;
           location = currentLocation;

            if(birds == b){
                return true;
            }
        }
    }
    return false;
}
int solve(vector<int> v,int n,int b){

    sort(v.begin(),v.end());
  
    int start = 0;
    int end = v[n-1] - v[0];
    int ans = -1;

    while(start <= end){
        int mid = start + ((end - start)/2);

        bool birds = checkPositions(v,n,b,mid);

        if(birds){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
int main(){
    
    vector<int> v = {1,2,4,8,9};
    cout<<solve(v,v.size(),3);
    return 0;
}
