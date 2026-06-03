#include <iostream>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
    //Initialize the varibles
    int n = landStartTime.size(), m = waterStartTime.size();
    //precompute the minimum time to complete a ride for both types
    int minLandFinish = INT_MAX, minWaterFinish = INT_MAX;
    //store the answer in a variable
    int ans = INT_MAX;

    //first, precompting the min time taken to complete a land ride
    for(int i = 0; i < n; i++) {
        minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
    }

    //second, precomputing the min time taken to complete a water ride
    for(int j = 0; j < m; j++) {
        minWaterFinish = min(minWaterFinish, waterStartTime[j] + waterDuration[j]);
    }

    //checking which land ride might give the earliest possible completion for both ride types
    for(int i = 0; i < n; i++) {
        int landFinish = max(minWaterFinish, landStartTime[i]) + landDuration[i];
        ans = min(ans, landFinish);
    }

    // now, checking for water rides
    for(int j = 0; j < m; j++) {
        int waterFinish = max(minLandFinish, waterStartTime[j]) + waterDuration[j];
        ans = min(ans, waterFinish);
    }

    return ans;         //returning the stored answer
}


int main() {
    vector<int> landStartTime = {5};
    vector<int> landDuration = {3};
    vector<int> waterStartTime = {1};
    vector<int> waterDuration = {10};

    cout << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
    return 0;
}