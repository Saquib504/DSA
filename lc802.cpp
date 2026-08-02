#include <iostream>
using namespace std;


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> adj(V);
    vector<int> inDegree(V, 0);
    vector<int> safeStates;

    for(int i = 0; i < V; i++) {
        inDegree[i] = graph[i].size();
        for(int nbr : graph[i]){
            adj[nbr].push_back(i);
        }
    }

    queue<int> q;

    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0)q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();   q.pop();
        safeStates.push_back(node);

        for(int nbr : adj[node]) {
            if(--inDegree[nbr] == 0)q.push(nbr);
        }
    }

    sort(safeStates.begin(), safeStates.end());
    return safeStates;
}

