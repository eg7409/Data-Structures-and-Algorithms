#include <bits/stdc++.h>
using namespace std;


//Longest band

int longest(vector<int> v){

    unordered_set<int> s;
    for(auto i : v){
        s.insert(i);
    }

    int res = 0,c=0;

    for(auto element : s){
        int parent = element - 1;
        
        if(s.find(parent) == s.end()){
            c = 1;
            int next = element + 1;
            while(s.find(next) !=s.end()){
                next++;
                c++;
            }
        }
        res = max(res,c);
    }
    return res;
}
int main(){

   vector<int> v = {1,9,3,0,18,5,2,4,10,7,12,6};
   cout<<longest(v)<<endl;
	return 0;
}
