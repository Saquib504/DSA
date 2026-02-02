#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> map;
    stack<int> stk;

    for(int i = nums2.size() - 1; i >= 0; i--) {
        while(!stk.empty() && stk.top() <= nums2[i]) {
            stk.pop();
        }

        map[nums2[i]] = stk.empty() ? -1 : stk.top();

        stk.push(nums2[i]);
    }

    vector<int> res(nums1.size());

    for(int i = 0; i < nums1.size(); i++ ){
        res[i] = map[nums1[i]];
    }

    return res;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> res = nextGreaterElement(nums1, nums2);

    for(int val : res) {
        cout << val << " ";
    }
    cout << endl;
}