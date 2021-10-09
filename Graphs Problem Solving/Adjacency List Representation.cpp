#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Adjacency List Representation

class Graph
{
    int vertex;
    list<int> *v;

public:
    Graph(int val)
    {
        vertex = val;
        v = new list<int>[vertex];
    }

    void addEdge(int i, int j)
    {
        v[i].push_back(j);
        v[j].push_back(i);
    }

    void print()
    {

        for (int i = 0; i < vertex; i++)
        {
            cout << i << " --> ";

            for (auto j : v[i])
            {
                cout << j << " ,";
            }

            cout << endl;
        }
    }
};

int main()
{

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);

    g.print();

    return 0;
}
