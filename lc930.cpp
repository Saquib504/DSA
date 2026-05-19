#include <iostream>
#include <vector>
using namespace std;

int countAtMost(const vector<int>& nums, int goal) {
    if (goal < 0) return 0;

    int l = 0;
    int sum = 0;
    int count = 0;

    for (int r = 0; r < static_cast<int>(nums.size()); r++) {
        sum += nums[r];

        while (sum > goal) {
            sum -= nums[l];
            l++;
        }

        count += (r - l + 1);
    }

    return count;
}

int numSubarraysWithSum(const vector<int>& nums, int goal) {
    return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
}


int main() {
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal) << endl; // Output: 4
    return 0;
}