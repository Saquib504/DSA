#include <iostream>
using namespace std;


int minimumEffortPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = 0;
    pq.push({dist[0][0], {0, 0}});

    int dr[] = {0,-1,0,1};
    int dc[] = {-1,0,1,0};

    while(!pq.empty()) {
        auto it = pq.top();    pq.pop();
        int diff = it.first, r = it.second.first, c = it.second.second;

        if(r == n-1 && c == m-1) return diff;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int minEffort = max(diff, abs(grid[r][c] - grid[nr][nc]));
                if(dist[nr][nc] > minEffort) {
                    dist[nr][nc] = minEffort;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }
    return -1;
}


int main() {
    int n; cout << "Enter the size of the grid(NxN), input n: "; cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout << "The path with the minimum effort in the Binary Matrix is : " << minimumEffortPath(grid) << endl;

    return 0;
}