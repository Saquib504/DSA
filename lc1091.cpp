#include <iostream>
using namespace std;


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    q.push({0,0});

    if(grid[0][0] != 0 || grid[n-1][n-1] != 0)return -1;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[0][0] = 1;

    int dr[] = {0,-1,-1,-1,0,1,1,1};
    int dc[] = {-1,-1,0,1,1,1,0,-1};

    while(!q.empty()) {
        auto [r,c] = q.front(); q.pop();

        if(r == n-1 && c == n-1)return dist[r][c];

        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
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

    cout << "The shortest path in the Binary Matrix is : " << shortestPathBinaryMatrix(grid) << endl;

    return 0;
}