#include<bits/stdc++.h>
using namespace std;

// n nodes
// m edges
// There are two ways to represent a Graph: a) Matrix way, b) List way

void matrixWay(int &n, int &m)
{
    // Matrix Way: T(n) = O(n square)
    int adj[n+1][m+1];
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void listWayUndirected(int &n, int &m)
{
    // List Way for UnDirected Graph: T(n) = O(2E) as each edge is storing 2 nodes.
    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void listWayDirected(int &n, int &m)
{
    // List Way for Directed Graph: T(n) = O(E).
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
}

void weightedGraph(int &n, int &m)
{
    // Here we will store in pairs alongside with adjacent node.
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        int weight;
        cout << "Enter Weight: ";
        cin >> weight;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
}

int main()
{
    int n, m;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of m: ";
    cin >> m;

    matrixWay(n, m);

    return 0;
}