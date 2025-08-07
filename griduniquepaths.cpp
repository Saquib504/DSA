#include <iostream>
using namespace std;

/*Below i have written soluton to a single problem in multiple ways*/

//Recursion + Memoization
// int f(int i, int j, vector<vector<int>>&memo) {
//     if( i == 0 && j == 0){
//         return 1;
//     }

//     if(i < 0 || j < 0) {
//         return 0;
//     }

//     if(memo[i][j] != -1) return memo[i][j];

//     int up = f(i-1, j, memo);
//     int left = f(i, j-1, memo);

//     return memo[i][j] = up + left;
// }


int countWays(int m, int n) {
    vector<vector<int>>memo(m, vector<int>(n, -1));
    // return f(m-1, n-1, memo);

    //Tabulation Method : bottom up
    /*for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if( row == 0 && col == 0) {
                memo[row][col] = 1;
                continue;
            }

            int up = 0, left = 0;

            if(row > 0)
                up = memo[row-1][col];
            if(col > 0)
                left = memo[row][col-1];

            memo[row][col] = up + left;
        }
    }
    return memo[m-1][n-1];*/


    //Space Optimized:

    vector<int>prev(n, 0);

    for(int row = 0; row < m; row++) {
        vector<int> temp(n,0);
        for(int col = 0; col < n; col++) {
            if(row == 0 && col == 0) {
                temp[col] = 1;
                continue;
            }

            int up = 0, left = 0;

            if(row > 0)
                up = prev[col];
            if(col > 0)
                left = temp[col-1];

            temp[col] = up + left;
        }
        prev = temp;
    }

    return prev[n-1];
}

int main() {
    int m = 3; 
    int n = 3;

    cout << countWays(m,n) << endl;

    return 0;
}