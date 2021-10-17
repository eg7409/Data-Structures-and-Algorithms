#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Dijkshtra's Algorithm

class Graph
{
    int vertex;
    list<pair<int,int> > *l;

public:
    Graph(int v)
    {
        vertex = v;
        l = new list<pair<int,int> >[vertex];
    }

    void addEdge(int x, int y,int wt)
    {
        l[x].push_back({wt,y});
        l[y].push_back({wt,x});
    }

    int shortestPath(int source,int destination){
        vector<int> visited(vertex,INT_MAX);
        set<pair<int,int> > s;

        visited[source] = 0;
        s.insert({visited[source],source});

        while(!s.empty()){

            auto it = s.begin();
            int node = it->second;
            int totalDistance = it->first;
            s.erase(it);

            for(auto i : l[node]){

                int curr_dist = i.first;
                int curr_node = i.second;

                if(totalDistance + curr_dist < visited[curr_node]){

                    auto f = s.find({visited[curr_node],curr_node});

                    if(f != s.end()){
                        s.erase(f);
                    }

                    visited[curr_node] = totalDistance + curr_dist;
                    s.insert({visited[curr_node],curr_node});
                }
            }
        }

        for(int i=0;i<vertex;i++){
            cout<<"Node i "<<i<<" distance "<<visited[i]<<endl;
        }

        return visited[destination];
    }

};


int main(){

    Graph g(5);

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    cout<<g.shortestPath(0,4);
    

    return 0;
}
