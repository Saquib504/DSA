#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//TC -> O(N*M), SC -> O(1)
// int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
//                        vector<int>& waterStartTime, vector<int>& waterDuration) {
//     int n = landStartTime.size();
//     int m = waterStartTime.size();
//     int ans = INT_MAX;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             // Option 1: Land ride i → Water ride j
//             int landFinish = landStartTime[i] + landDuration[i];
//             int waterStart = max(landFinish, waterStartTime[j]);
//             int waterFinish = waterStart + waterDuration[j];
//             ans = min(ans, waterFinish);

//             // Option 2: Water ride j → Land ride i
//             int wFinish = waterStartTime[j] + waterDuration[j];
//             int lStart = max(wFinish, landStartTime[i]);
//             int lFinish = lStart + landDuration[i];
//             ans = min(ans, lFinish);
//         }
//     }

//     return ans;
// }

//TC -> O(N + M), SC -> O(1)
int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    
    int n = landStartTime.size(), m = waterStartTime.size();
    int ans = INT_MAX;

    int minLandFinish = INT_MAX, minWaterFinish = INT_MAX;

    //precompute the min finish time for land and water rides
    for(int i = 0; i < n; i++) {
        minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
    }
    for(int i = 0; i < m; i++) {
        minWaterFinish = min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
    }

    //Option 1: Land ride → Water ride
    for(int j = 0; j < m; j++) {
        int waterFinish = max(minLandFinish, waterStartTime[j]) + waterDuration[j];
        ans = min(ans, waterFinish);
    }
    //Option 2: Water ride → Land ride
    for(int i = 0; i < n; i++) {
        int landFinish = max(minWaterFinish, landStartTime[i]) + landDuration[i];
        ans = min(ans, landFinish);
    }

    return ans;
}
int main() {
    vector<int> landStartTime = {2, 8};
    vector<int> landDuration  = {4, 1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration  = {3};

    cout << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl; // 9
    return 0;
}