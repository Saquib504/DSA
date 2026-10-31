#include <iostream>
using namespace std;
static constexpr int MOD = 1e9+7;

int func(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> & memo) {
    if(i >= n || j >= m) return 0;
    if(i == n-1 && j == m-1) return 1;

    if(memo[i][j] != -1) return memo[i][j];
    

    int right = 0, down = 0;
    //if right is not out of bounds
    if(j+1 < m) {
        if(grid[i][j+1] == 1) {
            right = func(i+1, j+1, n, m, grid, memo);
        } else {
            right = func(i, j+1, n, m, grid, memo);
        }
    }

    //if down is not out of bounds
    if(i+1 < n) {
        if(grid[i+1][j] == 1) {
            down = func(i+1, j+1, n, m, grid, memo);
        } else {
            down = func(i+1, j, n, m, grid, memo);
        }
    }

    return memo[i][j] = (down + right) % (int)(1e9+7);
}

int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return func(0, 0, n, m, grid, memo);
}


int main() {
    
    int n, m; cout << "Enter n and m: "; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    cout << "Enter the grid[i][j] : ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }


    cout << "Total unique twisted mirror paths : " << uniquePaths(grid) << endl;
    return 0;
}