#include <bits/stdc++.h>
using namespace std;


//Longest band

int longest(vector<int> v){

    set<int> s;
    int n = v.size();

    for(auto i : v){
        s.insert(i);
    }
    v.clear();
    for(auto i:s){
        v.push_back(i);
    }
    int res = 0;
    int c =0;
    int val=0;
    for(int i=0;i<n;){
       val=v[i]+1;
       i++;
       c=1;
       while(val==v[i]){
           c++;
           i++;
           val++;
       }
       cout<<endl;
       res = max(res,c);
    }
    return res;
}
int main(){

   vector<int> v = {1,9,3,0,18,5,2,4,10,7,12,6};
   cout<<longest(v)<<endl;
	return 0;
}
