#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> per, depth;
vector<vector<int>> up;
const int MOD = 1e9 + 7, LOG = 20;


int power(long long a, long long b) {
    long long ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return (int)ans;
}


int countWays(int d) {
    if(d == 0) return 0;

    return power(2, d-1);
}

void dfs(int node, int p, int d, vector<vector<int>>& adj) {
    depth[node] = d;
    up[node][0] = (p == -1) ? node : p;
    for (int j = 1; j < LOG; j++)
        up[node][j] = up[up[node][j-1]][j-1];
    for (auto nbr : adj[node])
        if (nbr != p)
            dfs(nbr, node, d + 1, adj);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++)
        if ((diff >> j) & 1)
            u = up[u][j];
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--)
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    return up[u][0];
}

int dist(int u, int v) {
    int l = lca(u,v);

    int d = depth[u] + depth[v] - 2*depth[l];

    return d;
}

 vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size() + 2;
    vector<vector<int>> adj(n);

    for(auto edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    per.resize(n, -1);
    depth.resize(n, 0);
    up.resize(n, vector<int>(LOG, -1));

    dfs(1, -1, 0, adj);

    vector<int> ans;

    for(auto q : queries) {
        int u = q[0], v = q[1];

        ans.push_back(countWays(dist(u, v)));
    }

    return ans;
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

    int q; cout << "Enter number of queries: ";
    cin >> q;
    vector<vector<int>> queries;
    cout << "Enter query (u, v): " << endl;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        queries.push_back({u,v});
    }
    vector<int> result = assignEdgeWeights(edges, queries);
    for(auto ways : result) {
        cout << ways << ", ";
    }
    cout << endl;
    return 0;
}