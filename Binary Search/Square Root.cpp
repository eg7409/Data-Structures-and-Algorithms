#include<bits/stdc++.h>
using namespace std;

//Square Root

float squareroot(int n,int p){
    int start = 0, end = n;
    float ans = 0;
    while(start <= end){
        int mid = start + ((end - start)/2);

        if(mid*mid == n){
            return mid;
        }
        if(mid*mid < n){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    float increase = 0.1;
    for(int i=1;i<=p;i++){

        while(ans*ans < n){
            ans += increase;
        }
        ans -= increase;
        increase /= 10;
    }
    return ans;
}
int main(){


    cout<<squareroot(10,3);
  return 0;
}
