#include <iostream>
using namespace std;



int countAtMost(vector<int>& nums, int k) {
    if(k < 0) return 0;
    int n = nums.size();
    int l = 0, count = 0, sum = 0;

    for(int r = 0; r < n; r++) {
        sum += nums[r] % 2;

        while(sum > k) {
            sum -= nums[l] % 2;
            l++;
        }

        count += r - l + 1;
    }

    return count;
}

int niceSubarrays(vector<int>& nums, int k) {
    return countAtMost(nums, k) - countAtMost(nums, k-1);
}

int main() {
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout << niceSubarrays(nums, k) << endl;
    return 0;
}