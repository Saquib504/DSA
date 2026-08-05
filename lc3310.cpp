#include <iostream>
using namespace std;

vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> adj(n);

    for(auto edge : invocations) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> isSuspicious(n, false);        //created to keep check of all suspicious nodes

    // Applied dfs to traverse connected suspicious nodes
    auto dfs = [&](auto& self, int u) -> void {
        isSuspicious[u] = true;
        for(int v : adj[u]) {
            if(!isSuspicious[v]) {
                self(self, v);
            }
        }
    };
    dfs(dfs, k);

    bool cannotRemove = false;
    for(const auto& edge : invocations) {
        int u = edge[0], v = edge[1];
        if(!isSuspicious[u] && isSuspicious[v]) {
            cannotRemove = true;
            break;
        }
    }

    vector<int> result;

    if(cannotRemove) {
        for(int i = 0; i < n; i++)result.push_back(i);
    }
    else {
        for(int i = 0; i < n; i++) {
            if(!isSuspicious[i])result.push_back(i);
        }
    }

    return result;
}

int main() {
    int n, k; cout << "Enter n and k : "; cin >> n >> k;
    vector<vector<int>> invocations;

    cout << "Enter the [u,v] edges : \n";

    while(true) {
        int u, v; cin >> u >> v;
        if(u == -1 || v == -1)break;
        else invocations.push_back({u, v});
    }

    vector<int> ans = remainingMethods(n, k, invocations);

    cout << "The remaning non suspicious nodes after removal are : ";
    for(auto x : ans) {cout << x << " ";}cout << endl;

    return 0;
}