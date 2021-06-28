#include<bits/stdc++.h>
using namespace std;

//String Window
string window(string s,string p){

  vector<int> pattern_frequnency(256);
  vector<int> string_frequency(256);
  int n = s.length(),m= p.length();

  for(int i=0;i<m;i++){
    pattern_frequnency[p[i]]++;
  }

  int count = 0;
  int start = 0;
  int windowLength = 0;
  int minWindowLength = INT_MAX;
  int startIndex = 0;

  for(int i=0;i<n;i++){
    string_frequency[s[i]]++;

    if(pattern_frequnency[s[i]]!=0 && pattern_frequnency[s[i]]>= string_frequency[s[i]]){
      count++;
    }

    if(count == m){

      while(pattern_frequnency[s[i]]==0 || pattern_frequnency[s[start]] < string_frequency[s[start]]){
        string_frequency[s[start]]--;
        start++;
      }

      windowLength = i-start + 1;
      if(windowLength < minWindowLength){
        minWindowLength = windowLength;
        startIndex = start;
      }
    }
  }
  return s.substr(startIndex,minWindowLength);
}

int main(){
  cout<<window("Eishita","itsa");
  return 0;
}
