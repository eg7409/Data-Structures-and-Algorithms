#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Shortest Path using BFS

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

    void print()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << i << " -- >";

            for (auto j : l[i])
            {
                cout << j << " ,";
            }

            cout << endl;
        }
    }

    void bfs(int source,int destination)
    {
        bool *visi = new bool[vertex]{false};
        int *parent = new int[vertex]{-1};
        int *dist = new int[vertex]{0};

        queue<int> q;
        q.push(source);
        dist[source] = 0;
        parent[source] = -1;

        visi[source] = true;

        while (!q.empty())
        {

            int val = q.front();
            q.pop();

            cout << val << " ";

            for (auto i : l[val])
            {
                if (!visi[i])
                {
                    visi[i] = true;
                    parent[i] = val;
                    dist[i] = dist[val] + 1;
                    q.push(i);
                }
            }
        }
        cout<<endl;
        for(int i=0;i<vertex;i++){
            cout<<"The shortest path from "<<i<<" is "<<dist[i]<<endl;
        }

        int temp = destination;

        while(temp!=source){
            cout<<temp<<"->";
            temp = parent[temp];
        }
        cout<<source;
    }
};

int main()
{

    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.bfs(1,6);

    return 0;
}
