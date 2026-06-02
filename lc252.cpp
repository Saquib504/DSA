#include <iostream>
#include <vector>
using namespace std;


//TC -> O(NlogN + N), SC -> O(2N)
 static bool comparator(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
int maxMeetings(vector<int>& start, vector<int>& end){
    //your code goes here
    int n = start.size();
    vector<vector<int>> meeting(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        meeting[i][0] = start[i];
        meeting[i][1] = end[i];
    }

    sort(meeting.begin(), meeting.end(), comparator);

    int cnt = 1;
    int lastEnd = meeting[0][1];

    for(int i = 1; i < n; i++) {
        if(meeting[i][0] > lastEnd) {
            cnt++;
            lastEnd = meeting[i][1];
        }
    }

    return cnt;
}



int main() {
    vector<int> start = {0,3,1,5,5,8};
    vector<int> end = {5,4,2,9,7,9};
    cout << maxMeetings(start, end) << endl;
    return 0;
}