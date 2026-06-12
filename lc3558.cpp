/*
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, 
where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.

Since the answer may be large, return it modulo 109 + 7.

Note: Ignore all edges not in the path from node 1 to x.
*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007
int dfs(vector<vector<int>>& adj, int node, int parent) {
    int depth = 0;

    for (int child : adj[node]) {
        if (child == parent) continue;
        depth = max(depth, 1 + dfs(adj, child, node));
    }

    return depth;
}

int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n + 1);

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int depth = dfs(adj, 1, -1);

    long long res = 1;
    for (int i = 1; i < depth; i++) {
        res = (res * 2) % MOD;
    }

    return res;
}


int main() {
    int n; cout << "Enter number of edges: ";
    cin >> n;
    vector<vector<int>> edges;
    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    int result = assignEdgeWeights(edges);
    cout << "Number of ways to assign edge weights: " << result << endl;

    return 0;
}