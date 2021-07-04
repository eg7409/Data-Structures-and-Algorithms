#include <bits/stdc++.h>
using namespace std;

//Ladders

int ans=0;

int ladders(int n,int start){

    if(start > n){
        return 0;
    }
    if(start == n){
        return 1;
    }
    

    return ladders(n,start+1) +  ladders(n,start+2) + ladders(n,start+3);
}
int main(){
    
    cout<<ladders(4,0);
    return 0;
}
