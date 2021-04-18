#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;
    void addEdge(int v, int w);
    void BFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int v)
{
    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        if(!visited[c])
        {
            cout << c << " ";
            visited[c] = true;
        }
        for(auto i=adj[c].begin(); i!=adj[c].end(); ++i)
        {
            if(visited[*i] == false)
            {
                q.push(*i);
            }
        }
    }
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

    cout<< "The Breadth first Traversal of the Graph is : ";
    g.BFS(1);
}
