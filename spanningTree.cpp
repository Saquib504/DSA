#include <iostream>
using namespace std;

int spanningTree(int V, vector<vector<int>> &adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;
    vector<bool> vis(V, false);
    pq.push({0,0});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dist = it.first;

        if(vis[node])continue;
        vis[node] = true;
        sum += dist;

        for(auto x : adj[node]){
            if(!vis[x[0]]){
                pq.push({x[1],x[0]});
            }
        }
    }
    return sum;
}

int main(){
    int V = 4;
    vector<vector<int>> adj = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}
    };

    int sum = spanningTree(V, adj);

    cout << "The cost of MST is : " << sum << ".\n";
    return 0;
}