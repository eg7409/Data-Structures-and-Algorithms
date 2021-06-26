#include<bits/stdc++.h>
using namespace std;

//tokenisation using strtok

int main(){

  char c[1000];
  cin.getline(c,1000);

  char *token = strtok(c," ");

  while(token != NULL){
    cout<<token<<endl;
    token = strtok(NULL," ");
  }

  return 0;
}
