#include <bits/stdc++.h>
using namespace std;


int sparseSearch(vector<string> v,string t){
    int n = v.size();

    int start =0,end = n-1;

    while(start <= end){
        int mid = start + (end - start)/2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;

        if(v[mid] == ""){
            while(1){
                if(mid_left < start && mid_right > end){
                    return -1;
                }

                else if(mid_left >= start && v[mid_left]!=""){
                    mid = mid_left;
                    break;
                }

                else if(mid_right <= end && v[mid_right]!=""){
                    mid = mid_right;
                    break;
                }

                mid_left--;
                mid_right++;
            }
        }
        if(v[mid] == t){
            return mid;
        }
        else if(v[mid] > t){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
       
    }
    return -1;
}


int main(){

    vector<string> v = {"ai","","","bat","","","car","cat","","","dog","e"};
    string t = "dog";

    cout<<sparseSearch(v,t);
    return 0;
}
