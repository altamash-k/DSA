#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, storeDfs);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[])
{
    vector<int> storeDfs;
    vector<int> vis(v+1, 0);

    for(int i = 1; i <= v; i++)
    {
        if(!vis[i])
            dfs(i, adj, vis, storeDfs);
    }

    return storeDfs;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int>& ans)
{
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[6];
    
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);

    vector<int> df;
    df= dfsOfGraph(5, adj);
    for(auto it: df)
        cout<<it<<" ";

    return 0;
}