// Time Complexity: O(V!), where V is the number of vertices in the graph
// Space Complexity: O(V^2) + O(V)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix;
vector<int> path;
vector<bool> vis;
int V;

bool solve(int u)
{
    if(u == V)
    {
        return matrix[path[u - 1]][path[0]] == 1;
    }

    for(int v = 1; v < V; v++)
    {
        if(!vis[v] && matrix[path[u - 1]][v] == 1)
        {
            vis[v] = true;
            path[u] = v;
            if(solve(u + 1)) return true;
            vis[v] = false;
        }
    }
    return false;
}

int main()
{

    V = 5;
    matrix = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    path.resize(V);
    vis.assign(V, false);
    path[0] = 0;
    vis[0] = true;

    if(solve(1))
    {
        cout << "Hamiltonian Cycle: ";
        for(int i = 0; i < V; i++) cout << path[i] << " ";
        cout << path[0]; 
    }
    else
    {
        cout << "No Hamiltonian Cycle exists";
    }
    return 0;
}