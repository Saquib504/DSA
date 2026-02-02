#include <iostream>
 #include <stack>
 #include <vector>

 using namespace std;
 
 // Function to find the next greatest element for each element in a circular array
 // TC -> O(N), SC -> O(N)
 vector<int> nextGreatestElement2(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;

    for(int i = n-1; i>= 0; i--) {
        stk.push(nums[i]);
    }

    for(int i = n-1; i >= 0; i--) {
        while(!stk.empty() && stk.top() <= nums[i]) {
            stk.pop();
        }

        ans[i] = stk.empty() ? -1 : stk.top();

        stk.push(nums[i]);
    }
    return ans;
 }

 //Slightly optimized code with better runtime and memory usage
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);

    for(int i = 2*n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums[i%n]) st.pop();
        if(i < n){
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i%n]);
    }

    return ans;
}

 int main() {
    vector<int> nums = {1, 3, 2, 4};

    vector<int> res = nextGreatestElement2(nums);

    for(auto x : res) {
        cout << x << " ";
    }cout << endl;

    return 0;
 }