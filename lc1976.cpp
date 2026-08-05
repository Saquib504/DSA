#include <iostream>
using namespace std;


int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);

    for(auto road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    vector<long long> dist(n, 1e18), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    int MOD = (int)(1e9 + 7);

    while(!pq.empty()) {
        auto [cost, node] = pq.top();   pq.pop();

        if(cost > dist[node]) continue;

        for(auto [nbr, edgW] : adj[node]) {
            //this is the first time we are traversing this shorter distance
            if(dist[nbr] > edgW + cost) {
                dist[nbr] = edgW + cost;
                pq.push({dist[nbr], nbr});
                ways[nbr] = ways[node];
            }
            //we are traversing this path not the first time, so add the extra paths
            else if(dist[nbr] == cost + edgW) {
                ways[nbr] = (ways[nbr] + ways[node])%MOD;
            }
        }
    }
    return ways[n-1]%MOD;
}

int main() {
    int n; cout << "Enter the value of n: "; cin >> n;
    vector<vector<int>> roads;

    while(true) {
        int u, v, edgW;
        cin >> u >> v >> edgW;
        if(u == -1 || v == -1 || edgW == -1)break;
        else roads.push_back({u, v, edgW});
    }

    cout << "The number of ways to traverse from 0 to n-1 with the shortest path is : " << countPaths(n, roads) << endl;

    return 0;
}