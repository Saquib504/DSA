#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[j][k] = best score at current row and column j,
// when exactly k neutralizations are still available (k in [0, 2]).
// We keep only one row (rolling DP), so memory is O(c * 3).
static int dp[500][3];

class Solution {
public:
    static int maximumAmount(vector<vector<int>>& coins) {
        const int r = coins.size(), c = coins[0].size();

        // Base cell (0,0):
        // k=0 means we must take coins[0][0] as-is.
        // k=1 or k=2 can choose to neutralize if it is negative, so max(0, x).
        int x = coins[0][0];
        dp[0][0] = x;
        dp[0][1] = dp[0][2] = max(0, x);

        // Fill the first row: only move right is possible.
        for (int j = 1; j < c; j++) {
            x = coins[0][j];
            for (int k = 2; k > 0; k--) {
                // Either take current cell normally, or neutralize this cell.
                dp[j][k] = max(x + dp[j - 1][k], dp[j - 1][k - 1]);
            }
            // No neutralizations available.
            dp[j][0] = x + dp[j - 1][0];
        }

        // Process remaining rows.
        for (int i = 1; i < r; i++) {
            // First column: only move down is possible.
            x = coins[i][0];
            for (int k = 2; k > 0; k--) {
                dp[0][k] = max(x + dp[0][k], dp[0][k - 1]);
            }
            dp[0][0] = x + dp[0][0];

            // Inner cells: choose the better parent from left or up.
            for (int j = 1; j < c; j++) {
                x = coins[i][j];
                for (int k = 2; k > 0; k--) {
                    // From left (dp[j-1][...]) or from up (old dp[j][...]).
                    // For each direction, either take x or neutralize x.
                    dp[j][k] = max(
                        max(x + dp[j - 1][k], dp[j - 1][k - 1]),
                        max(x + dp[j][k], dp[j][k - 1])
                    );
                }
                // k=0: no neutralization choice remains.
                dp[j][0] = x + max(dp[j][0], dp[j - 1][0]);
            }
        }

        // Answer at bottom-right with up to 2 neutralizations available initially.
        return dp[c - 1][2];
    }
};


int main() {
    vector<vector<int>> coins = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};
    cout << Solution::maximumAmount(coins) << endl;
    return 0;
}