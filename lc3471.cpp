#include <iostream>
using namespace std;


int largestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    
    if(k == n) return *max_element(nums.begin(), nums.end());

    int freq[51] = {0};
    for(int num : nums) freq[num]++;

    if(k == 1) {
        int ans = -1;
        for(int num : nums) {
            if(freq[num] == 1)ans = max(ans, num);
        }
        return ans;
    }

    int ans = -1;

    if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
    if(freq[nums[n-1]] == 1) ans = max(ans, nums[n-1]);

    return ans;
}

int main() {
    vector<int> nums;
    int k;

    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cin >> k;

    cout << "\nLargest almost missing element in nums array is " << largestInteger(nums, k) << endl;

    return 0;
}