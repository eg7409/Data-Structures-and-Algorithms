#include <bits/stdc++.h>
using namespace std;


//Smart Keypad

vector<string> keypad = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void solve(string input,string output,int i){

    if(input[i] == '\0'){
        cout<<output<<endl;
        return;
    }

    int digit = input[i] - '0';
    if(digit == 0 || digit == 1){
        solve(input,output,i+1);
    }

    for(int ind = 0;ind < keypad[digit].size();ind++){
        solve(input,output + keypad[digit][ind],i+1);
    }
}

int main(){

    string input = "23",output="";

    solve(input,output,0);
    return 0;
}
