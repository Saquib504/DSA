#include <iostream>
using namespace std;



int maxSumDivThree(vector<int>& nums) {
    const int NEG = -1000000000;
    vector<int> dp = {0, NEG, NEG};

    for (int num : nums) {
        vector<int> temp(dp);
        for (int r = 0; r < 3; r++) {

            if (dp[r] == NEG) continue;  // <-- IMPORTANT FIX

            int newSum = dp[r] + num;
            temp[newSum % 3] = max(temp[newSum % 3], newSum);
        }
        dp = temp;
    }

    return dp[0];
}




int main() {
    vector<int> nums = {3,6,5,1,8};
    cout << maxSumDivThree(nums) << endl;
    return 0;
}