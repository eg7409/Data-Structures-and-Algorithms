#include <bits/stdc++.h>
using namespace std;

//Ladders

int ans=0;

int ladders(int n,int start,int count){

    if(start > n){
        return 0;
    }
    if(start == n){
        return 1;
    }
    

    return ladders(n,start+1,count) +  ladders(n,start+2,count) + ladders(n,start+3,count);
}
int main(){
    
    cout<<ladders(1,0,0);
    return 0;
}
