#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Adjacency List Representation with Node Class

class Node
{

public:
    string name;
    list<string> neighbours;

    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{

    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->neighbours.push_back(y);

        if (undir)
        {
            m[y]->neighbours.push_back(x);
        }
    }

    void print()
    {

        for (auto i : m)
        {
            cout << i.first << " --> ";

            for (auto j : i.second->neighbours)
            {
                cout << j << " || ";
            }

            cout << endl;
        }
    }
};

int main()
{

    vector<string> cities{"Delhi", "London", "Paris", "New York"};

    Graph g(cities);

    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.print();

    return 0;
}
