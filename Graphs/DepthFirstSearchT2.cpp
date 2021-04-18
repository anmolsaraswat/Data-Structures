#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    for(auto i=adj[v].begin(); i!=adj[v].end(); ++i)
        if(visited[*i] == false)
            DFS(*i);
}

int main()
{
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);
    g.addEdge(3,9);
    g.addEdge(3,10);
    g.addEdge(2,5);
    g.addEdge(2,8);
    g.addEdge(5,8);
    g.addEdge(5,7);
    g.addEdge(8,7);
    g.addEdge(5,6);

    cout<< "The depth first Traversal of the Graph is : ";
    g.DFS(1);
}
