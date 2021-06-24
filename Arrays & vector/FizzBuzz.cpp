
#include <bits/stdc++.h>
using namespace std;

vector<string> FizzBuzz(int n){

    vector<string> result;

    for(int i=1;i<=n;i++){
        if(i%15==0){
            result.push_back("FizzBuzz");
        }
        else if(i%5==0){
            result.push_back("Buzz");
        }
        else if(i%3==0){
            result.push_back("Fizz");
        }
        else{
            result.push_back(to_string(i));
        }
    }
    return result;
}
int main(){

   vector<string> v = FizzBuzz(30);
   for(auto i : v){
       cout<<i<<" ";
   }
   cout<<endl;
	return 0;
}
