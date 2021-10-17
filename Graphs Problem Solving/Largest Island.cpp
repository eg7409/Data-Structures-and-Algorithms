#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > v,vector<vector<bool> > &visited,int row,int col,int n,int m){
    
    visited[row][col] = true;
    
    queue<pair<int,int> > q;
    q.push({row,col});
    
    int count = 1;
    
    vector<vector<int> > direc = {{0,1},{0,-1},{-1,0},{1,0}};
    
    while(!q.empty()){
        
        auto p = q.front();
        q.pop();
        
        for(auto d : direc){
            int x = p.first + d[0];
            int y = p.second + d[1];
            
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && v[x][y] == 1){
                count++;
                q.push({x,y});
                visited[x][y] = true;
            }
        }
    }
    return count;
}

int largest_island(vector<vector<int> > v){
    //return the size of largest island in grid
    
    int n = v.size();
    int m = v[0].size();
    
    vector<vector<bool> > visited(n,vector<bool>(m,false));
    
    int count = 0,ans = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && v[i][j] == 1){
                count = solve(v,visited,i,j,n,m);
                ans = max(ans,count);
            }
        }
    }
    return ans;
}

/*---------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > v,vector<vector<bool> > &visited,int i,int j,int n,int m){
        
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || v[i][j] == 0){
            return 0;
        }
        
        visited[i][j] = true;
        
        return (1 + solve(v,visited,i+1,j,n,m) + solve(v,visited,i-1,j,n,m) + solve(v,visited,i,j+1,n,m) +solve(v,visited,i,j-1,n,m));
    }

int largest_island(vector<vector<int> > v){
    //return the size of largest island in grid
    
    int n = v.size();
        int m = v[0].size();
        
        int ans = 0;
        
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 ans = max(ans,solve(v,visited,i,j,n,m));
            }
        }
        return ans;
}
