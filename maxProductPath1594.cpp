#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int maxProductPath(vector<vector<int>>& grid) {
    const long long MOD = 1000000007LL;
    const int r = static_cast<int>(grid.size());
    const int c = static_cast<int>(grid[0].size());

    vector<vector<long long>> mn(r, vector<long long>(c, 0));
    vector<vector<long long>> mx(r, vector<long long>(c, 0));

    mn[0][0] = mx[0][0] = grid[0][0];

    for (int j = 1; j < c; ++j) {
        mn[0][j] = mx[0][j] = mx[0][j - 1] * grid[0][j];
    }

    for (int i = 1; i < r; ++i) {
        mn[i][0] = mx[i][0] = mx[i - 1][0] * grid[i][0];
    }

    for (int i = 1; i < r; ++i) {
        for (int j = 1; j < c; ++j) {
            long long x = grid[i][j];
            long long a = x * mn[i - 1][j];
            long long b = x * mx[i - 1][j];
            long long d = x * mn[i][j - 1];
            long long e = x * mx[i][j - 1];

            mn[i][j] = min(min(a, b), min(d, e));
            mx[i][j] = max(max(a, b), max(d, e));
        }
    }

    long long ans = mx[r - 1][c - 1];
    return ans < 0 ? -1 : static_cast<int>(ans % MOD);
}

int main() {
    vector<vector<int>> grid = {{-1,-2,-3}, {-2,-3,-3}, {-3,-3,-2}};

    cout << maxProductPath(grid) << endl;

    return 0;
}