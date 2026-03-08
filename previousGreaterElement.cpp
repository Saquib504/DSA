#include <iostream>
using namespace std;

vector<int> findPGE(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;

    for(int i = 0; i < n; i++) {

        while(!stk.empty() && stk.top() <= nums[i]) {
            stk.pop();
        }

        ans[i] = stk.empty() ? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> res = findPGE(nums);
    for(auto num : res) {
        cout << num << " ";
    }cout << endl;
    return 0;
}