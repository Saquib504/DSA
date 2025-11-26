#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int f(int i, int j, int k, int sumModK, vector<vector<int>>&grid) {
    if(i >= grid.size() || j >= grid[0].size())return 0;
    int newSumModK = (sumModK + grid[i][j]) % k;

    if(i == grid.size() - 1 && j == grid[0].size() - 1) {
        return newSumModK == 0 ? 1 : 0;
    }

    long long ways = 0;

    ways += f(i+1, j, k, newSumModK, grid);
    ways %= MOD;
    ways += f(i, j+1, k, newSumModK, grid);
    ways %= MOD;

    return ways;
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

    //return f(0,0,k,0,grid);

    //Tabulation method
    dp[0][0][grid[0][0]%k] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0)continue;
            for(int sumModK = 0; sumModK < k; sumModK++) {
                
                long long ways = 0;
                if(i > 0)   ways += dp[i-1][j][sumModK];
                if(j > 0)   ways += dp[i][j-1][sumModK];

                int newSumModK = (sumModK + grid[i][j]) % k;

                dp[i][j][newSumModK] = (dp[i][j][newSumModK] + ways) % MOD;
            }
        }
    }
    return dp[m-1][n-1][0];
}


int main() {
    int k = 3;
    vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int result = numberOfPaths(grid, k);
    cout << "The number of paths in the matrix whose sum is divisible by k is : " << result << endl;
    return 0;
}