#include <iostream>
 #include <stack>
 #include <vector>

 using namespace std;

 vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        stack<int> stk;
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--) {
            stk.push(arr[i]);
        }
        
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && stk.top() <= arr[i]) {
                stk.pop();
            }
            
            ans[i] = stk.empty() ? -1 : stk.top();
        }
        
        return ans;
    }

 int main() {
    vector<int> nums = {1, 3, 2, 4};

    vector<int> res = nextGreater(nums);

    for(auto x : res) {
        cout << x << " ";
    }cout << endl;

    return 0;
 }