#include <iostream>
using namespace std;

void dfs(int u, vector<vector<int>>& grid, vector<bool>& vis) {
    vis[u] = true;
    int m = grid[0].size();

    for(int v = 0; v < m; v++) {
        if(grid[u][v] == 1 && !vis[v]) dfs(v, grid, vis);
    }
}


int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int m = isConnected[0].size();

    vector<bool> vis(n, false);
    int cnt = 0;

    for(int u = 0; u < n; u++) {
        if(!vis[u]) {
            dfs(u, isConnected, vis);
            cnt++;
        }
    }

    return cnt;
}


int main() {
    int n, m;
    cout << "Enter the size of the grid in NxM: "; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the element present in the grid row-wise : \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "The number of provinces present in the grid : " << findCircleNum(grid) << endl;

    return 0;
}