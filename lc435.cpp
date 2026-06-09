#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    int cnt = 0;
    int prevEnd = intervals[0][1];

    sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    for(int i = 1; i < n; i++) {
        //if current interval overlaps with previous interval
        if(prevEnd > intervals[i][0]) {
            cnt++;
        }
        else {
            prevEnd = intervals[i][1];
        }
    }
    return cnt;
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
    int result = eraseOverlapIntervals(intervals);
    cout << "Minimum number of intervals to remove: " << result << endl;

    return 0;
}