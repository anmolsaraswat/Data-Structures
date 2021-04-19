#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    map<int, vector<int>> adj;
    map<int, bool> visited;
    stack<int> ts;
public:
    Graph(int v);
    void addEdge(int src, int dst);
    void topSort();
    void topSortUtil(int val);
    void initialze();
};

Graph::Graph(int v)
{
    this->V = v;
}

void Graph::addEdge(int src, int dst)
{
    adj[src].push_back(dst);
}
void Graph::initialze()
{
    for(auto itr =adj.begin(); itr!=adj.end(); ++itr)
    {
        visited[itr->first] = false;
    }
}

void Graph::topSortUtil(int val)
{
    visited[val] = true;
    for(auto i=adj[val].begin(); i!=adj[val].end(); ++i)
    {
        if(!visited[*i])
            topSortUtil(*i);
    }
    ts.push(val);
}
void Graph::topSort()
{
    for(auto itr =adj.begin(); itr!=adj.end(); ++itr)
    {
        cout << itr->first << endl;
      //  if(visited[itr->first] == false)
      //      topSortUtil(itr->first);
    }

    while(ts.empty() == false)
    {
        cout << ts.top() << " ";
        ts.pop();
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
    g.initialze();
    g.topSort();

    return 0;
}
