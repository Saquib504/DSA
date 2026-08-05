#include <iostream>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);

    for(auto f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<pair<int, pair<int, int>>> q;
    //{stops, {cost, node}}
    q.push({0, {0, src}});


    while(!q.empty()) {
        auto it = q.front(); q.pop();
        int stops = it.first;
        int cost = it.second.first;
        int node = it.second.second;

        if(stops > k) continue;


        for(auto [nbr, edgW] : adj[node]) {
            if(edgW + cost < dist[nbr] && stops <= k) {
                dist[nbr] = edgW + cost;
                q.push({stops+1, {dist[nbr], nbr}});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int n, src, dst, k;
    cout << "Enter the value of n, src, dst and k: "; cin >> n >> src >> dst >> k;

    vector<vector<int>> flights;

    while(true) {
        int u, v, edgW;
        cin >> u >> v >> edgW;
        if(u == -1 || v == -1 || edgW == -1)break;
        else flights.push_back({u, v, edgW});
    }

    cout << "The cheapest flight with k stops is : " << findCheapestPrice(n,flights,src,dst,k) << endl;
    return 0;
}