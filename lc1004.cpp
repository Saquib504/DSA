#include <iostream>
using namespace std;


int longestOnes(vector<int>&nums, int k) {
    int n = nums.size(), l = 0, maxLen = 0, zerocnt = 0;

    for(int r = 0; r < n; r++) {
        if(nums[r] == 0)zerocnt++;

        if(zerocnt > k) {
            if(nums[l] == 0)zerocnt--;
            l++;
        }

        maxLen = max(maxLen, r-l+1);
    }

    return maxLen;
}

int main() {
    int k;
    cin >> k;
    vector<int> nums;

    while(true) {
        int num;
        cin >> num;
        if(num == -1)break;
        nums.push_back(num);
    }
    cout << longestOnes(nums, k) << endl;
}