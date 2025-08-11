#include <iostream>
using namespace std;


int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis(n, 0), lds(n, 0);

    vector<int> tails;
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        auto it = lower_bound(tails.begin(), tails.end(), x);
        int pos = it - tails.begin();
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
        lis[i] = pos + 1;
    }

    tails.clear();
    for (int i = n - 1; i >= 0; --i) {
        int x = nums[i];
        auto it = lower_bound(tails.begin(), tails.end(), x);
        int pos = it - tails.begin();
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
        lds[i] = pos + 1;
    }

    int maxMountain = 0;
    for (int i = 0; i < n; ++i) {
        if (lis[i] > 1 && lds[i] > 1)
            maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
    }

    // this problem is similar to 1671. Minimum Number of Removals to Make Mountain Array from leetcode
    // return n - maxMountain;    -> is the answer for that

    return maxMountain;
}

int main() {
    vector<int> nums = {1,11,2,10,4,5,2,1};

    cout << "The length of longest Bitonic subsequence : " << minimumMountainRemovals(nums) << endl;

    return 0;
}