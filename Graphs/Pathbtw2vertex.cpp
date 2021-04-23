#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<int> *adj;
public:
    Graph(int x);
    void addEdge(int src, int dst);
    bool checkPath(int u, int v);
};

Graph::Graph(int x)
{
    this->V = x;
    adj = new vector<int>[V];
}

void Graph::addEdge(int src, int dst)
{
    adj[src].push_back(dst);
}

bool Graph::checkPath(int u, int v)
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        visited[c] = true;
        if(c == v)
            return true;
        for(auto it=adj[c].begin(); it!=adj[c].end(); ++it)
        {
            if(!visited[*it])
            {
                q.push(*it);
            }
        }
    }
    return false;

}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,3);

    if(g.checkPath(1,3))
        cout << "We have a path from 1 to 3";
    return 0;
}

