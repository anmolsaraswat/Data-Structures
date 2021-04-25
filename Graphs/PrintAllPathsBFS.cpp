#include<bits/stdc++.h>
using namespace std;

void printPath(vector<int> &path)
{
    for(auto i=path.begin(); i!=path.end(); ++i)
        cout << *i << " ";
    cout << endl;
}

bool isPresent(int val, vector<int> &path)
{
    for(auto i=path.begin(); i!=path.end(); ++i)
        if(*i == val)
            return true;
    return false;
}

void findpaths(vector<vector<int>> g, int src, int dst, int v)
{
    queue<vector<int>> q;

    vector<int> path;

    path.push_back(src);
    q.push(path);

    while(!q.empty())
    {
        path = q.front();
        q.pop();
        int last = path[path.size()-1];
        if(last == dst)
            printPath(path);
        else
        {
            for(int i=0; i< g[last].size(); i++)
            {
                if(!isPresent(g[last][i], path))
                {
                    vector<int> newpath(path);
                    newpath.push_back(g[last][i]);
                    q.push(newpath);
                }
            }
        }
    }
}


int main()
{
    vector<vector<int> > g;
    int v = 4;
    g.resize(4);

    g[0].push_back(3);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(0);
    g[2].push_back(1);

    int src = 2, dst = 3;
    cout << "path from src " << src
         << " to dst " << dst << " are \n";

    findpaths(g, src, dst, v);

    return 0;
}
