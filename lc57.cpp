#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//My Solution
// Time Complexity: O(n), where n is the number of intervals
// Space Complexity: O(n), for the result vector
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;
    int start = newInterval[0];
    int end = newInterval[1];

    // add all intervals that end before the new interval starts
    while (i < n && intervals[i][1] < start) {
        res.push_back(intervals[i]);
        i++;
    }

    // merge overlapping intervals
    while (i < n && intervals[i][0] <= end) {
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        i++;
    }
    // add the merged interval
    res.push_back({start, end});

    // add remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
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
    vector<int> newInterval;
    cout << "Enter new interval (start end): ";
    int start, end;
    cin >> start >> end;
    newInterval.push_back(start);
    newInterval.push_back(end);
    vector<vector<int>> result = insert(intervals, newInterval);
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}