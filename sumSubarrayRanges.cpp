/*
Solution 2, O(n) Stack Solution

Follow the explanation in 907. Sum of Subarray Minimums

Intuition

res = sum(A[i] * f(i))
where f(i) is the number of subarrays,
in which A[i] is the minimum.

To get f(i), we need to find out:
left[i], the length of strict bigger numbers on the left of A[i],
right[i], the length of bigger numbers on the right of A[i].

Then,
left[i] + 1 equals to
the number of subarray ending with A[i],
and A[i] is single minimum.

right[i] + 1 equals to
the number of subarray starting with A[i],
and A[i] is the first minimum.

Finally f(i) = (left[i] + 1) * (right[i] + 1)

For [3,1,2,4] as example:
left + 1 = [1,2,1,1]
right + 1 = [1,3,2,1]
f = [1,6,2,1]
res = 3 * 1 + 1 * 6 + 2 * 2 + 4 * 1 = 17

Explanation

To calculate left[i] and right[i],
we use two increasing stacks.

It will be easy if you can refer to this problem and my post:
901. Online Stock Span
I copy some of my codes from this solution.

Complexity

All elements will be pushed twice and popped at most twice
Time O(n)
Space O(n)

*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    long res = 0, n = nums.size(), j , k;

    stack<int> stk;

    for(int i = 0; i <= n; ++i) {
        while(!stk.empty() && nums[stk.top()] > (i == n ? -2e9 : nums[i])) {
            j = stk.top(); stk.pop();
            k = stk.empty() ? -1 : stk.top();

            res -= (long)nums[j] * (i-j)*(j-k);
        }
        stk.push(i);
    }


    stk = stack<int>();

    for(int i = 0; i <= n; ++i) {
        while(!stk.empty() && nums[stk.top()] < (i == n ? 2e9 : nums[i])) {
            j = stk.top(); stk.pop();

            k = stk.empty() ? -1 : stk.top();

            res += (long)nums[j] * (i-j) * (j-k);
        }
        stk.push(i);
    }

    return res;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    cout << "Sum of subarray ranges: " << subArrayRanges(nums) << endl;
    return 0;
}