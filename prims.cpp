#include <iostream>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    int sum = 0;

    vector<bool> vis(V, false);

    pq.push({0,0});


    while(!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(vis[node])continue;
        vis[node] = true;
        sum += dist;

        for(auto &x : adj[node]) {
            int nbr = x[0];
            int edgeW = x[1];

            if(!vis[nbr]) {
                pq.push({edgeW, nbr});
            }
        }
    }
    return sum;
}


int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int mstWt = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}