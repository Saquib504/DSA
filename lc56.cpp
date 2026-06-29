#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// My Solution
// Time Complexity: O(n log n), where n is the number of intervals (due to sorting)
// Space Complexity: O(n), for the result vector
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;
    sort(intervals.begin(), intervals.end());

    while(i < n) {
        if(res.empty() || res.back()[1] < intervals[i][0]) {
            res.push_back(intervals[i]);
            i++;
        }
        else {
            res.back()[1] = max(intervals[i][1], res.back()[1]);
            i++;
        }
    }

    return res;
}



int main() {
    int n; cout << "Enter number of intervals: ";
    cin >> n;
    vector<vector<int>> intervals;
    cout << "Enter intervals (start end): " << endl;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});
    }
    vector<vector<int>> result = merge(intervals);
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}