#include <bits/stdc++.h>
using namespace std;

//Minimum swaps needed to sort an array

int swaps(vector<int> v ){

    //making a loop logic
    int n = v.size();

    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        p[i].first = v[i];
        p[i].second = i;
    }
    sort(p,p+n);

    vector<bool> visited(n,false);
    int count = 0,ans=0;

    for(int i=0;i<n;i++){

        if(visited[i]==true || p[i].second == i){
            continue;
        }

        int next = i;
        count=0;
        while(!visited[next]){
            visited[next] = true;
            next = p[next].second;
            count++;
        }
        ans += (count-1);
    }
    return ans;
}
int main(){

    vector<int> v = {1,2,3,4,5,8,6,9,7,10,11};
    cout<<swaps(v)<<endl;
	return 0;
}
