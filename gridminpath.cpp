#include <iostream>
using namespace std;



// int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&memo) {
//     if(i == 0 && j == 0) {
//         return memo[i][j] = grid[i][j];
//     }
//     if(i < 0 || j < 0) return INT_MAX;
    
//     if(memo[i][j] != -1) return memo[i][j];

//     int up = f(i-1, j, grid, memo);
//     int left = f(i, j-1, grid, memo);

//     return memo[i][j] = grid[i][j] + min(up, left);
// }

int countMinPath(vector<vector<int>>&grid) {
    int m = grid.size();
    int n = grid[0].size();

    if(grid[0][0] == -1 || grid[m-1][n-1] == -1) return -1;

    vector<vector<int>>memo(m, vector<int>(n,-1));

    // return f(m-1, n-1, grid, memo);

    //Tabulation Method
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             if(i == 0 && j == 0) {
//                 memo[i][j] = grid[i][j];
//                 continue;
//             }

//             int up = INT_MAX;
//             int left = INT_MAX;

//             if(i > 0) up = memo[i-1][j];
//             if(j > 0) left = memo[i][j-1];

//             memo[i][j] = grid[i][j] + min(up, left);
//         }
//     }
//     return memo[m-1][n-1];

    //Space optimization
    vector<int>prev(n, INT_MAX);

    for(int i = 0; i < m; i++) {
        vector<int>temp(n, INT_MAX);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                temp[j] = grid[i][j];
                continue;
            }

            int up = INT_MAX;
            int left = INT_MAX;

            if(i > 0) up = prev[j];
            if(j > 0) left = temp[j-1];

            temp[j] = grid[i][j] + min(up, left);
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {
    vector<vector<int>>grid = {{1, 1,1,1,1}, {60,70,60,19,1},{1,1,1,1,1},{1,50,40,20,22}, {1,1,1,1,1}};

    cout << countMinPath(grid) << endl;
    return 0;
}