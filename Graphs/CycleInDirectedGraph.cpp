#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    bool isCyclicUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

bool Graph::isCyclicUtil(int v, bool visited[])
{
    if(visited[v] == true)
        return true;
    visited[v] = true;
    for(int i=0; i<adj[v].size(); ++i)
    {
        if(isCyclicUtil(adj[v][i], visited))
            return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<V; i++)
    {
        visited[i] = true;
        for(int j=0; j<adj[i].size(); ++j)
        {
            if(isCyclicUtil(adj[i][j], visited))
                return true;
        }
        visited[i] = false;
    }
    return false;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle.";

    return 0;

}


