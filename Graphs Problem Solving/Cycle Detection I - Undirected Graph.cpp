#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Graph
{
    int vertex;
    list<int> *l;

public:
    Graph(int v)
    {
        vertex = v;
        l = new list<int>[vertex];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }   

    bool cycle(int node,bool *visited, int parent){
        visited[node] = true;

        for(auto i : l[node]){

            if(!visited[i]){
                if(cycle(i,visited,node)){
                    return true;
                }
            }
            else if(i!=parent){
                return true;
            }
        }
        return false;
    } 
};


bool contains_cycle(int v,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(v);

    for(int i=0;i<edges.size();i++){
        g.addEdge(edges[i].first,edges[i].second);
    }
    

    bool *visited = new bool[v]{false};

    return g.cycle(0,visited,-1);
}
