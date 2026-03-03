#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> window;
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if(i >= k-1) window.push_back(nums[dq.front()]);
    }

    return window;
}

int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}