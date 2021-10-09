#include <bits/stdc++.h>
#define ll long long
using namespace std;

// BFS

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

    void bfs(int source)
    {
        bool *visi = new bool[vertex]{false};

        queue<int> q;
        q.push(source);

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
                    q.push(i);
                }
            }
        }
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

    g.bfs(1);

    return 0;
}
