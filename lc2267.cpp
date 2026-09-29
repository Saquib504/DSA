#include <iostream>
#include <string>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> memo;

// bool solve(int i, int j, int cnt) {
//     cnt += (grid[i][j] == '(' ? 1 : -1);

//     if(cnt < 0 || cnt > (n+m-1 - (i+j))) return false;
//     if(i == n-1 && j == m-1) return cnt == 0;

//     if(memo[i][j]) return memo[i][j];

//     int down = false, right = false;
//     if(i+1 < n)down = solve(i+1, j, cnt);
//     if(j+1 < m)right = solve(i, j+1, cnt);

//     return memo[i][j] = down || right;
// }

// bool hasValidPath(vector<vector<char>>& input_grid) {
//     int n = input_grid.size(), m = input_grid[0].size();
//     //base-case => If the grid is not of even length then return false;
//     if((n+m-1) % 2 != 0) return false;
//     memo.assign(n, vector<bool>(m, false));
//     return solve(0, 0, 0);
// }



// OPTIMAL APPROACH
// TC ->
// SC -> 
bool hasValidPath(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
    if((n+m+1) % 2 != 0) return false;

    vector<bitset<201>> dp(m);

    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < m; ++col) {
            bitset<201> bits;

            if(row == 0 && col == 0) {
                bits.set(0);
            } else{
                if(row > 0) bits |= dp[col];
                if(col > 0) bits |= dp[col-1];
            }

            dp[col] = (grid[row][col] == '(') ? (bits << 1) : (bits >> 1);
        }
    }

    return dp[m-1].test(0);
}

int main() {
    cout << "Enter size of the grid(NxM) : "; cin >> n >> m;
    grid.assign(n, vector<char>(m));
    cout << "Enter the grid cell values : ";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    if(hasValidPath(grid)) {
        cout << "YES!" << endl;
    } else {
        cout << "NO!!" << endl;
    }

    return 0;
}