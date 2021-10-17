#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node{

    public:
    int x,y,distance;

    Node(int x,int y,int dist){
        this->x = x;
        this->y = y;
        this->distance = dist;
    }
};

class comp{

    public:

    bool operator()(Node a, Node b){
        return a.distance<=b.distance;
    }
};

int shortest_path(vector<vector<int> > v){
    //return the shortest path len
    
    int n = v.size();
    int m = v[0].size();

    vector<vector<int> > direction = {{0,1},{0,-1},{1,0},{-1,0}};

    vector<vector<int> > dist(n+1,vector<int>(m+1,INT_MAX));

    set<Node,comp> s;

    dist[0][0] = v[0][0];

    s.insert(Node(0,0,dist[0][0]));

    while(!s.empty()){
        auto i = s.begin();
        int x = i->x;
        int y = i->y;
        int d = i->distance;
        s.erase(i);

        for(auto di : direction){
            int nx = x + di[0];
            int ny = y + di[1];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && d + v[nx][ny] < dist[nx][ny]){
                
                Node temp(nx,ny,dist[nx][ny]);

                if(s.find(temp) != s.end()){
                    s.erase(temp);
                }

                dist[nx][ny] = d + v[nx][ny];
                s.insert(Node(nx,ny,dist[nx][ny]));
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return dist[n-1][m-1];
}


int main(){

    vector<vector<int> > v = {{31,100,65,12,18},
                              {10,13,47,157,6},
                              {100,113,174,11,33},
                              {88,124,41,20,140},
                              {99,32,111,41,20}};

    cout<<shortest_path(v)<<endl;
    return 0;
}
