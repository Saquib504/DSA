#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;

    for(int i = n-1; i >= 0; i--) {
        while(!stk.empty() && stk.top() >= nums[i]) {
            stk.pop();
        }

        ans[i] =stk.empty() ? -1 : stk.top();
        stk.push(nums[i]);
    }

    return ans;
}


int main() {
    vector<int>nums = {4,8,5,2,25};

    vector<int> res = nextSmallerElement(nums);

    for(auto num : res) {
        cout << num << " ";
    }cout << endl;

    return 0;
}