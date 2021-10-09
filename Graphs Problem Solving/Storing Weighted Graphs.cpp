#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Storing Weighted Graphs

class Graph
{
    int vertex;
    list<pair<int, int>> *l; // u-->{wt,v}

public:
    Graph(int v)
    {
        vertex = v;
        l = new list<pair<int, int>>[vertex];
    }

    void addEdge(int u, int v, int wt, bool undir = true)
    {
        l[u].push_back({wt, v});

        if (undir)
        {
            l[v].push_back({wt, u});
        }
    }
};

int main()
{

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    
    return 0;
}
