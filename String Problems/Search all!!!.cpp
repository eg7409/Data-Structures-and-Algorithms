#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    
    int index = 0;
    
    while(index!=-1){
        index = big.find(small,index);
        if(index!=-1){
            result.push_back(index);
            index++;
        }
    }
    return result;
}
int main(){
    
	vector<int> v = stringSearch("movie movie","movie");
	for(auto i : v){
		cout<<i<<" ";
	}
  return 0;
}
