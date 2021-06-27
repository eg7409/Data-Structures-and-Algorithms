#include<bits/stdc++.h>
using namespace std;

//Housing Implementation + Negative Numbers

// MAIN IDEA:
// we will create a map to store the prefix sum with their indexes
// we will iterate through the vector and sum += v[i]
// if the sum == target then yes we have found the answer from index = 0 to index = i;
// else we will check map[sum - target] exists in the map or not, if yes ->ANSWER : map[sum - target] + 1 to i;, 
//                                                                if no then push the current sum with thier index in the map



vector<pair<int,int> > subarray(vector<int> v,int target){
  int n = v.size();
  vector<pair<int,int> > p;
  int sum = 0;
  map<int,int> m;

  for(int i=0;i<n;i++){
    sum += v[i];

    if(sum == target){
      p.push_back({0,i});                                  //sum == target from 0th index (EASY)
      return p;                                            // the above equation can be rewritten --> sum - target = 0;   NO
    }                                                     //    basically the equation is   -->
                                                          //                                    sum - target - x = x - x; ----> sum - target - x = 0;
    if(m.find(sum - target) != m.end()){                  //    so we are finding this x in the map
      p.push_back({m[sum-target]+1,i});                   // Here if the x is present in the map, we will remove that element(basically not removing), and take the next index
      return p;
    }
      
    m[sum] = i;                                           // if the x is not present in map ot the map is empty(at 1st iteration), we map current sum and its index.
   }    
  
  
  p.push_back({-1,-1}); // NO subarray found
  return p;  
}

int main(){
  
  vector<pair<int,int> > v = subarray({10,10,2,-2,-20,10},-10);
  
  for(auto i : v){
    cout<<i.first<<" "<<i.second<<endl;
  }
  return 0;
}
