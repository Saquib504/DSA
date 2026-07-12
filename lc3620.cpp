#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

static bool dijkstra(int mid, int n, ll k, const vector<vector<Edge>>& adj) {
    vector<ll> res(n, LLONG_MAX);
    // Min-heap storing: {current_total_cost, node}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    res[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // Early pruning if the total cost already exceeds k
        if (d > k) continue; 
        if (d > res[node]) continue; // Skip stale elements

        if (node == n - 1) return true;

        for (const auto& edge : adj[node]) {
            // If the edge capacity is less than our binary search target, skip it
            if (edge.cost < mid) continue;

            if (d + edge.cost < res[edge.to]) {
                res[edge.to] = d + edge.cost;
                pq.push({res[edge.to], edge.to});
            }
        }
    }
    return false;
}

int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    int n = online.size();
    
    // Use vector instead of unordered_map to prevent TLE/MLE and clear states properly
    vector<vector<Edge>> adj(n);
    int l = INT_MAX;
    int r = 0;

    for (const auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int cost = e[2];

        if (!online[u] || !online[v]) continue;

        adj[u].push_back({v, cost});
        l = min(l, cost);
        r = max(r, cost);
    }

    // If no edges were added or node 0 has no paths out
    if (r == 0 && l == INT_MAX) return -1;

    int answer = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (dijkstra(mid, n, k, adj)) {
            answer = mid; // Valid capacity, let's look for a higher bottleneck
            l = mid + 1;
        } else {
            r = mid - 1;  // Too restrictive, lower the capacity requirement
        }
    }

    return answer;
}

// Fast I/O
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 'c';
}();
int main() {
    int n; cout << "Enter number of nodes: "; cin >> n;
    ll k; cout << "Enter the value of k: "; cin >> k;
    
    vector<vector<int>> edges;

    cout << "Enter the edge in the following manner: {u,v,cost}\n";
    while(true) {
        int u, v, cost;
        cin >> u >> v >> cost;
        if(u  == -1 || v == -1 || cost == -1)break;
        edges.push_back({u,v,cost});
    }

    vector<bool> online(n, false);
    cout << "Enter the online status for each node (0 -> Offline | 1 -> Online) : ";
    for(int i = 0; i < n; i++) {
        int n; cin >> n;
        if(n == 0) {
            online[i] = false;
        } else {
            online[i] = true;
        }
    }

    cout << "The maximum Score for the best network recovery path is : " << findMaxPathScore(edges, online, k) << endl;
    return 0;
}