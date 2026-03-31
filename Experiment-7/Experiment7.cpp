// Time Complexity: O(k * E)
//      where k = maximum number of stops allowed, E = number of flights (edges)
// Space Complexity: O(n)
//      where n = number of nodes

#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> cost(n, INT_MAX);
    cost[src] = 0;
    for(int i = 0; i <= k; i++)
    {
        vector<int> tmp(cost);
        for(auto edge : flights)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if(cost[u] != INT_MAX && tmp[v] > cost[u] + w)
            {
                tmp[v] = cost[u] + w;
            }
        }
        cost = tmp;
    }
    if(cost[dst] != INT_MAX) return cost[dst];
    return -1;
}

int main()
{
    int n = 4;
    int src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {
        {0,1,40},
        {0,2,100},
        {1,2,20},
        {1,3,150},
        {2,3,30}
    };
    cout<<"Cheapest Price: "<<findCheapestPrice(n, flights, src, dst, k);
    return 0;
}