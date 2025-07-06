#include <iostream>
#include <vector>
using namespace std;

int f(int i, int j, const vector<vector<int>>& grid, vector<vector<int>>& memo) {
    if(i > 0 && j > 0 && grid[i][j] == 1) return 0;

    if(i == 0 && j == 0) return 1;

    if(i < 0 || j < 0) return 0;

    if(memo[i][j] != -1) return memo[i][j];

    int up = f(i-1, j, grid, memo);
    int left = f(i ,j-1, grid, memo);

    return memo[i][j] = up + left;
}

// int f(int i, int j, const vector<vector<int>>& grid, vector<vector<int>>& memo) {
//     if (i < 0 || j < 0) return 0;              // Out of bounds
//     if (grid[i][j] == 1) return 0;             // Obstacle
//     if (i == 0 && j == 0) return 1;            // Base case

//     if (memo[i][j] != -1) return memo[i][j];

//     int up = f(i - 1, j, grid, memo);
//     int left = f(i, j - 1, grid, memo);

//     return memo[i][j] = up + left;
// }


int countWays(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1) return 0;

    // vector<vector<int>> memo(m, vector<int>(n, -1));
    // return f(m - 1, n - 1, grid, memo);

    //Tabulation Method:
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(i >= 0 && j >= 0 && grid[i][j] == 1) {
    //             memo[i][j] = 0;
    //             continue;
    //         }
    //         if(i == 0 && j == 0) {
    //             memo[i][j] = 1;
    //             continue;
    //         }

    //         int up = 0, left = 0;

    //         if(i > 0) up = memo[i-1][j];
    //         if(j > 0) left = memo[i][j-1];

    //         memo[i][j] = up + left;
    //     }
    // }
    // return memo[m-1][n-1];


    //Space optimized method:

    vector<int>prev(n, 0);

    for(int i = 0; i < m; i++) {
        vector<int>temp(n,0);
        for(int j = 0; j < n; j++) {
            if(i >= 0 && j >= 0 && grid[i][j] == 1) {
                temp[j] = 0;
                continue;
            }

            if(i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

            int up = 0, left = 0;

            if(i > 0) up = prev[j];
            if(j > 0) left = temp[j-1];

            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {
    // vector<vector<int>> grid = { {0, 1, 0, 0, 0},{0, 1, 0, 1, 0},{0, 0, 0, 1, 0}};

    // cout << countWays(grid) << endl;  // ✅ Expected Output: 1
    // return 0;

    vector<pair<vector<vector<int>>, int>> tests = {
        {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 6},
        {{{0, 1}, {1, 0}}, 0},
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 0},
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2},
        {vector<vector<int>>(10, vector<int>(10, 0)), 48620},
        {vector<vector<int>>(15, vector<int>(15, 0)), 40116600},
        {{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0},
        {{{0, 0, 0}, {0, 0, 0}, {0, 0, 1}}, 0}
    };

    int testNum = 1;
    for (auto &[grid, expected] : tests) {
        int result = countWays(grid);
        cout << "Test Case " << testNum++ << ": ";
        cout << "Output = " << result << ", Expected = " << expected;
        if (result == expected) cout << " ✅";
        else cout << " ❌";
        cout << endl;
    }
}
