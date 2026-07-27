#include <iostream>
using namespace std;


void bfs(int startRow, int startCol, vector<vector<char>>&grid) {
    int n = grid.size();
    int m = grid[0].size();

    grid[startRow][startCol] = 0;

    queue<pair<int, int>> q;
    q.push({startRow, startCol});

    int drow[] = {0,-1,0,1};
    int dcol[] = {-1,0,1,0};

    while(!q.empty()) {
        auto [row, col] = q.front();    q.pop();

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1') {
                q.push({nrow, ncol});
                grid[nrow][ncol] = '0';
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1') {
                cnt++;
                bfs(i,j, grid);
            }
        }
    }

    return cnt;
}

int main() {
    int n, m;
    cout << "Enter the size of the grid in NxM: "; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter the element present in the grid row-wise : \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "The number of islands present in the grid : " << numIslands(grid) << endl;

    return 0;
}