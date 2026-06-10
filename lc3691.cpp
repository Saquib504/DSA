#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <bit>
#include <cstdint>
using namespace std;

// Eunice's Solution
// Time Complexity: O((n + k)log n) for building the sparse table and O(k log n) for processing the priority queue
// Space Complexity: O(n log n) for the sparse table
class SparseTable {
    vector<vector<int>> Min, Max;

    public:
    SparseTable(const vector<int>& num) {
        size_t n = num.size();
        int w = bit_width(n);
        Min.resize(w, vector<int>(n));
        Max.resize(w, vector<int>(n));

        for (int i = 0; i < n; i++)
            Min[0][i] = Max[0][i] = num[i];

        for (int i = 1; i < w; i++)
            for (int j = 0; j + (1 << i) <= n; j++) {
                Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
                Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
            }
    }

    int query(int left, int right) {
        int k = bit_width((uint32_t)right - left) - 1;
        return max(Max[k][left], Max[k][right - (1 << k)]) -
            min(Min[k][left], Min[k][right - (1 << k)]);
    }
};

long long maxTotalValue(vector<int>& nums, int k) {
    int n = nums.size();
    long long res = 0;
    SparseTable LUT(nums);

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < n; i++)
        pq.emplace(LUT.query(i, n), i, n);

    while (get<0>(pq.top()) && k--) {
        auto [val, l, r] = pq.top();
        pq.pop();
        res += val;
        pq.emplace(LUT.query(l, r - 1), l, r - 1);
    }

    return res;
}


int main() {
    int n, k;
    cout << "Enter number of elements and k: ";
    if (!(cin >> n >> k)) {
        return 0;
    }
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    long long result = maxTotalValue(nums, k);
    cout << "Maximum total value: " << result << endl;
    return 0;
}