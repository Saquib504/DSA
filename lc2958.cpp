#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//Don't do such below stupud things. YOU ARE DECLARING A GLOBAL 4GB ARRAY ---- the fuck!!!
// const long MAX = 1e9;
// int count[MAX+1] = {0};

int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    int ans = 0;
    unordered_map<int, int> count;

    for(int r = 0; r < n; r++) {
        count[nums[r]]++;
        
        while(count[nums[r]] > k) {
            count[nums[l]]--;
            l++;
        }

        ans = max(ans, (r-l+1));
    }

    return ans;
}


int main() {
    vector<int> nums;
    cout << "Enter the elements in the nums array: ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        else nums.push_back(n);
    }

    int k; cout << "Enter the value of k: "; cin >> k;

    cout << "The length of the longest good subarray of nums is " << maxSubarrayLength(nums, k) << endl;

    return 0;
}