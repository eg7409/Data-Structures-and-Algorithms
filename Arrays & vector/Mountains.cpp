#include <bits/stdc++.h>
using namespace std;

//finding the peak in the array
int mountain(vector<int> v){
    
    int n = v.size();

    int peak = 0,count=0,j = 0;
    for(int i=1;i<n-1;){

        if(v[i]>v[i-1] && v[i]>v[i+1]){
            count=1;

            j = i;
            while(j>0 && v[j] > v[j-1]){
                j--;
                count++;
            }

            i;
            while(i<n-1 && v[i]>v[i+1]){
                i++;
                count++;
            }
            
            peak = max(peak,count);
        }
        else{
            i++;
        }
    }
    return peak;
}

int main(){

    vector<int> v = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-1,4};
    cout<<mountain(v)<<endl;	
	return 0;
}




/*

#include <bits/stdc++.h>
using namespace std;


//Mountain
int checkleft(vector<int> v,int i){

    int count = 0;

    while(i>0 && v[i-1] < v[i]){
        count++;
        i--;
    }
    return count;
}

int checkright(vector<int> v,int i){

    int count =0;


    while(i<v.size() -1 && (v[i] > v[i+1])){
        i++;
        count++;
    }
    return count;
}

int solve(vector<int> v){

    int mountain = 0;
    int n = v.size();

    for(int i=1;i<n-1;){
        if(v[i-1] < v[i] && v[i] > v[i+1]){
            int ind1 = checkleft(v,i);
            int ind2 = checkright(v,i);

           

            mountain = max(mountain,ind1+ind2+1);
    

            i = i+ ind2;
        }
        else{
            i++;
        }
    }
    return mountain;
}

int main(){


    vector<int> v ={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-1,4};
    cout<<solve(v);
    
    return 0;
}



*/
