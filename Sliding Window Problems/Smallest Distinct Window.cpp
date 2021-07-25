#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string s){
    //Complete this method
    
    map<char,int> m;
    int i=0,j=0;
    
    int n = s.length();
    int c = 0;
    int index = 0;
    int maxi=INT_MIN;
    
    while(j<n){
        
        if(m.find(s[j])!=m.end()&& m[s[j]] >= i){
            i = m[s[j]] + 1;
            c = j-i;   
        }
        
        m[s[j]] = j;
        j++;
        c++;
        
        if(maxi <= c){
            maxi = c;
            index = i;
        }
    }
    return s.substr(index,maxi);
}
/*
(same concept)

#include <bits/stdc++.h>
using namespace std;

//Smallest Distinct Window

string solve(string s){

    int n = s.length();

    map<char,int> m;

    int i=0;
    int length=0,maxLength=0,index=0;

    for(int j=0;j<n;j++){

        auto it = m.find(s[j]);
        if(it!=m.end()){
            if(m[s[j]] >= i){
                length = j-i;
                if(maxLength<length){
                    maxLength = length;
                    index = i;
                }
                i = m[s[j]] + 1;
                m[s[j]] = j;
            }
            else{
                m[s[j]] = j;
            }
        }
        else{
                m[s[j]] = j;
            }
            
    }
  
    return s.substr(index,maxLength);
}

int main(){

   
    string s = "aabcbcdbcaaad";
    cout<<solve(s);

    return 0;
}
*/
