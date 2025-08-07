#include <iostream>
#include <fstream>
using namespace std;


int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&memo, int &maxi) {

    if(i < 0 || j < 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];


    int up = f(i-1, j,grid, memo, maxi);
    int diagonal = f(i-1,j-1,grid, memo, maxi);
    int left = f(i, j-1, grid, memo, maxi);

    if(grid[i][j] == 1) {
        memo[i][j] = 1 + min({up,left,diagonal});
        maxi = max(maxi, memo[i][j]);
        return memo[i][j];
    } else {
        memo[i][j] = 0;
        return 0;
    }
}


int getMaxSquare(vector<vector<int>>&grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxi = 0;

    vector<vector<int>>memo(m, vector<int>(n,-1));

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         f(i,j,grid,memo,maxi);
    //     }
    // }
    // return maxi*maxi;

    //Tabulation Method:
    // for(int i = 0; i < m; i++) {
    //     memo[i][0] = grid[i][0];
    // }
    // for(int j = 0; j<n;j++){
    //     memo[0][j] = grid[0][j];
    // }

    // memo[0][0] = grid[0][0];


    // for(int i = 1; i < m; i++) {
    //     for(int j = 1; j < n; j++) {
    //         if(grid[i][j] == 1) {
    //             memo[i][j] = 1 + min({memo[i-1][j], memo[i][j-1], memo[i-1][j-1]});
    //         }

    //         maxi = max(maxi, memo[i][j]);
    //     }
    // }

    //Optimized version. --->  TC = O(M*N), SC.  ---> O(N)
    vector<int>prev(n,0);
    for(int j = 0; j < n; j++) {
        prev[j] = grid[0][j];
    }

    for(int i = 1;i < m; i++) {
        vector<int>temp(n,0);
        temp[0] = grid[i][0];
        for(int j = 1; j < n; j++) {
            
            if(grid[i][j] == 1) {
                temp[j] = 1 + min({temp[j-1], prev[j-1], prev[j]});
            }
            maxi = max(maxi, temp[j]);
        }
        prev = temp;
    }


    return maxi*maxi;
}

int main() {
    vector<vector<int>>grid = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout << getMaxSquare(grid) << endl;
    return 0;
}