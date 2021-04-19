#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
public:
    Graph(int v);
    void addEdge(int src, int dst);
    void topSort();
    void topSortUtil(int v, bool visited[], stack<int> &s);
};

Graph::Graph(int v)
{
    this->V = v;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dst)
{
    adj[src].push_back(dst);
}
void Graph::topSortUtil(int v, bool visited[], stack<int> &s)
{
    visited[v] = true;
    for(auto i=adj[v].begin(); i!=adj[v].end(); ++i)
    {
        if(!visited[*i])
            topSortUtil(*i, visited, s);
    }
    s.push(v);
}

void Graph::topSort()
{
    bool visited[V];
    stack<int> s;
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
            topSortUtil(i, visited, s);
    }

    while(s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topSort();

    return 0;

}
