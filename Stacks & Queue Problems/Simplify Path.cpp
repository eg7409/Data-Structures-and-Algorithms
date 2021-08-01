#include <bits/stdc++.h>
using namespace std;

//Simplify Path

string simplifyPath(string s){
   //complete this code return the simplified path
   
   stringstream ss(s);

   vector<string> v;

   string token;

   while(getline(ss,token,'/')){
       if(token == "." || token == ""){
           continue;
       }
       v.push_back(token);
   }

   
   vector<string> st;

   if(s[0] == '/'){               //for absolute path
       st.push_back("");
   }

   for(string i :v){
       if(i == ".."){
           if(st.size() == 0 || st[st.size() - 1] == ".."){
               st.push_back(i);
           }
           else if(st[st.size()-1]!=""){
               st.pop_back();          //for absolute path
           }
       }
       else{
           st.push_back(i);
       }
   }

   if(st.size() == 1 && st[0] == ""){
       return "/";
   }

   stringstream oss;
   int f = 0;
   for(auto i :st){
       if(f!=0){
           oss<<"/";
       }
       oss<<i;
       f++;
   }
   return oss.str();
}

int main()
{
    string s = "/../x/y/../z/././w/a///../../c/./";
    cout<<simplifyPath(s);
    
    return 0;
}
