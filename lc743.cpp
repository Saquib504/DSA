#include <iostream>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n+1);

    for(auto time : times) {
        adj[time[0]].push_back({time[1], time[2]});
    }

    vector<int> cost(n+1, INT_MAX);
    cost[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while(!pq.empty()) {
        auto [timeSoFar, node] = pq.top(); pq.pop();

        if(timeSoFar > cost[node])continue;

        for(auto& [nbr, t] : adj[node]) {
            if(cost[nbr] > t + timeSoFar) {
                cost[nbr] = t + timeSoFar;
                pq.push({cost[nbr], nbr});
            }
        }
    }
    int minTime = 0;

    for(int i = 1; i <= n; i++) {
        minTime = max(minTime, cost[i]);
    }

    return minTime == INT_MAX ? -1 : minTime;
}

int main() {
    int n, k;
    cout << "Enter the value of n and k: "; cin >> n >> k;

    vector<vector<int>> times;

    cout << "Enter {u, v, edgW}: \n";
    while(true) {
        int u, v, edgW;
        cin >> u >> v >> edgW;
        if(u == -1 || v == -1 || edgW == -1)break;
        else times.push_back({u, v, edgW});
    }

    cout << "The minimum time taken to send signal to each node is : " << networkDelayTime(times,n, k) << endl;
    return 0;
}