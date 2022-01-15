#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s = "thequickbrownfox";
vector<string> word = {"the", "quickbrown","fox","quick","brown"};
unordered_set<string> m;



int solve(int i){

	if(s[i] == '\0'){
		return 0;
	}

	int ans = INT_MAX;

	string curr = "";

	for(int j=i;j<s.size();j++){
		curr += s[j];

		if(m.find(curr) != m.end()){
			int rem = solve(j+1);

			if(rem!=-1){
				 ans = min(ans,1+rem);
			}
		}
	}

	if(ans==INT_MAX){
		return -1;
	}

	return ans;
}


int main(){

	for(int i=0;i<word.size();i++){
		m.insert(word[i]);
	}
	
	cout<<solve(0)-1;
	

	return 0;
}
