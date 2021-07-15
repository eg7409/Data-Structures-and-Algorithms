#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<char> > v,int row,int col){

    // check rows with passed col
    for(int i=0;i<row;i++){
        if(v[i][col] == 'Q'){
            return false;
        }
    }

    //Upper Left

    for(int i = row,j=col ; i>=0 && j>=0 ; i--,j--){
        if(v[i][j] == 'Q'){
            return false;
        }
    }

    //Upper right

    for(int i = row,j = col ; i>=0 && j<v.size() ; i--,j++){
        if(v[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool queen(vector<vector<char> > &v,int i,int &count){

    if(i == v.size()){
        count++;
        return true;
    }

    bool res = false;
    for(int j = 0;j<v.size();j++){
        if(isSafe(v,i,j)){
            v[i][j] = 'Q';


            res = queen(v,i+1,count) || res;

            v[i][j] = '0';
        }
    }
    return res;
}


int nQueen(int n){
//Write your code below. Do not modify this function or parameters. You can use helper function if needed.    
vector<vector<char> > v(n,vector<char>(n,'0'));
    int count = 0;
    queen(v,0,count);
    
    return count;

}
