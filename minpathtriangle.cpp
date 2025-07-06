#include <iostream>
using namespace std;

// int f(int i, int j, vector<vector<int>>grid, vector<vector<int>>&memo) {
//     if(i == grid.size()-1) return grid[i][j];

//     if(memo[i][j] != -1) return memo[i][j];

//     int downFirst = f(i+1, j, grid, memo);
//     int downSecond = f(i+1, j+1, grid, memo);

//     return memo[i][j] = grid[i][j] + min(downFirst, downSecond);
// }

int minpath(vector<vector<int>>&grid) {
    int n = grid.size();
    // vector<vector<int>>memo(m, vector<int>(m,-1));
    // return f(0,0, grid, memo);

    vector<int> front(n ,0);

    for(int j = 0; j < n; j++)front[j] = grid[n-1][j];

    for(int i = n-2; i >= 0; i--) {
        vector<int>current(n,0);
        for(int j = i; j >= 0; j--) {

            int upFirst = front[j];
            int upSecond = front[j+1];


            current[j] = grid[i][j] + min(upFirst, upSecond);
        }
        front = current;
    }
    return front[0];

}


int main() {
    vector<vector<int>> grid = {{2},{3,4},{6,5,7},{4,1,8,3},{7,2,9,7,3}};

    cout << minpath(grid) << endl;

    return 0;
}