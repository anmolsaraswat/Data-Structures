#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int src, int dst);
    bool isConnected();
    void DFSUtil(int i, bool visited[]);
    bool isEven();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dst)
{
    adj[src].push_back(dst);
    adj[dst].push_back(src);
}

void Graph::DFSUtil(int a, bool visited[])
{
    visited[a] = true;
    vector<int>::iterator i;
   // cout << a;
    for(i = adj[a].begin(); i!= adj[a].end(); ++i)
    {
       // cout << *i;
        if(!visited[*i])
            DFSUtil(*i, visited);
    }

}

bool Graph::isConnected()
{
    bool visited[V];
    int i;
    for(i=0; i<V; i++)
        visited[i] = false;

    //DFS
    for(i=0; i<V; i++)
        if(adj[i].size()!=0)
            break;

    DFSUtil(i, visited);

    for(int i=0; i<V; i++)
        if(visited[i] == false)
            return false;

    return true;
}
bool Graph::isEven()
{
    for(int i=0; i<V; i++)
    {
        if(adj[i].size()%2 !=0)
            return false;
    }
    return true;
}


int main()
{
    Graph g4(4);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.addEdge(1, 3);

    if(g4.isConnected() && g4.isEven())
        cout << "The graph has Eulerian Cycle.";
    else
        cout << "The graph has no Eulerian Cycle.";
}
