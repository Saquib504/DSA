#include <iostream>
using namespace std;

// int f(int i, int j, int n, vector<vector<int>>&grid, vector<vector<int>>&memo) {
//     if(j < 0 || j > n) return -1e9;

//     if(i == 0) return grid[0][j];

//     if(memo[i][j] != -1) return memo[i][j];

//     int left = f(i-1, j-1, n, grid, memo);
//     int down = f(i-1 ,j, n, grid, memo);
//     int right = f(i-1, j+1, n, grid, memo);


//     return memo[i][j] = grid[i][j] + max(down, max(left, right));
// }


int maxPathSum(vector<vector<int>>&grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>memo(m, vector<int>(n, -1));

    // int pathSum = INT_MIN;
    // for(int i = 0; i < n; i++) {
    //     int ans = f(m-1, i, n, grid, memo);
    //     pathSum = max(pathSum, ans);
    // }

    // return pathSum;


    //Tabulation Method
    // //Base case
    // for(int i = 0; i < n; i++) {
    //     memo[0][i] = grid[0][i];
    // }


    // for(int i = 1; i < m; i++) {
    //     for(int j = 0; j < n; j++) {

    //         int left = (j > 0) ? memo[i-1][j-1] : -INT_MAX;
    //         int up = memo[i-1][j];
    //         int right = (j < n-1) ? memo[i-1][j+1] : -INT_MAX;


    //         memo[i][j] = grid[i][j] + max(up, max(left, right));
    //     }
    // }

    // int pathSum = -INT_MAX;

    // for(int i = 0; i < n; i++) {
    //     pathSum = max(pathSum, memo[m-1][i]);
    // }

    // return pathSum;



    //Spcae optimization

    vector<int>prev(n, 0);
    for(int i = 0; i < n; i++) {
        prev[i] = grid[0][i];
    }

    for(int i = 1; i < m; i++) {
        vector<int>current(n, 0);
        for(int j = 0; j < n; j++) {

            int left = (j > 0) ? prev[j-1] : -INT_MAX;
            int down = prev[j];
            int right = (j < n) ? prev[j+1] : -INT_MAX;


            current[j] = grid[i][j] + max(down, max(left, right));
        }
        prev = current;
    }

    int pathSum = -INT_MAX;
    for(int i = 0; i < n; i++) {
        pathSum = max(pathSum, prev[i]);
    }

    return pathSum;
 }

int main() {
    vector<vector<int>> grid = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};

    cout << maxPathSum(grid) << endl;
    return 0;
}