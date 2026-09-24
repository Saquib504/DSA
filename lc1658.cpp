#include <iostream>
#include <numeric>

using namespace std;

int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int target = totalSum - x;
    if(target < 0) return -1;
    if(target == 0) return n;

    int l = 0;
    int maxLen = -1, currentSum = 0;

    for(int r = 0; r < n; r++) {
        currentSum += nums[r];
        while(currentSum > target && l <= r) {
            currentSum -= nums[l];
            l++;
        }
        if(currentSum == target) {
            maxLen = max(maxLen, r-l+1);
        }
    }

    return (maxLen == -1) ? -1 : n - maxLen;
}

int main() {
    vector<int> nums;
    int x;
    cout << "Enter elements of nums : ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cout << "Enter x : "; cin >> x;

    cout << "Minimum operations to reduce x to zero : " << minOperations(nums, x) << endl;
    return 0;
}