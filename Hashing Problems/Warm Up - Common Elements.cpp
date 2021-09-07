#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    //Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    vector<int> v(v1.size()+v2.size());
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    auto end = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    
    vector<int> ans;
    auto i = v.begin();
    
    while(i!=end){
        ans.push_back(*i);
        i++;
    }
    return ans;
}
