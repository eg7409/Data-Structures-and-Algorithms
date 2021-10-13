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
    }

    bool dfs(int node, vector<bool> &visited, vector<bool> &stack)
    {
        visited[node] = true;
        stack[node] = true;

        for (auto i : l[node])
        {

            if (stack[i] == true)
            {
                return true;
            }
            else if (!visited[i])
            {
                if (dfs(i, visited, stack))
                {
                    return true;
                }
            }
        }

        stack[node] = false;
        return false;
    }
};

bool contains_cycle(int v, vector<pair<int, int>> edges)
{
    //Complete this method
    Graph g(v);

    for (int i = 0; i < edges.size(); i++)
    {
        g.addEdge(edges[i].first, edges[i].second);
    }

    vector<bool> visited(v, false);
    vector<bool> stack(v, false);

    

    return g.dfs(0, visited, stack);
}
