#include <iostream>
using namespace std;


int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(), sum = 0;
    vector<int> vis(n, false);
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;

        for(int j = 0; j < n; j++) {
            if(!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        vis[u] = true;
        sum += dist[u];


        for(int v = 0; v < n; v++) {
            if(!vis[v]) {
                int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                dist[v] = min(dist[v], cost);
            }
        }
    }
    return sum;
}

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << minCostConnectPoints(points) << endl;
    return 0;
}