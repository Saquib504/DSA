#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNSE(vector<int> & nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;

    for(int i = n-1; i >= 0; i--) {
        while(!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }

        ans[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }

    return ans;
}


vector<int> findPSE(vector<int> & nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        while(!stk.empty() && nums[stk.top()] > nums[i]) {
            stk.pop();
        }

        ans[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }

    return ans;
}



int sumSubarrayRanges(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse = findNSE(nums);
    vector<int> pse = findPSE(nums);

    int total = 0, mod = (int)(1e9 + 7);

    for(int i = 0; i < n; i++) {
        int left = i - pse[i];
        int right = nse[i] - i;

        int maxVal = max(nums[left], nums[right]);
        int minVal = min(nums[left], nums[right]);

        //total = (total + (left*right*nums[i])%mod)%mod;
        total = total + maxVal - minVal;
    }
    return total;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << sumSubarrayRanges(nums) << endl;

    return 0;
}