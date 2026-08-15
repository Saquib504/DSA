#include <iostream>
using namespace std;

int longestSubsequence(vector<int>& nums) {
    int n = nums.size();
    int resultXOR = 0;
    bool allZero = true;

    for(auto &num : nums) {
        resultXOR ^= num;

        if(num != 0)allZero = false;
    }

    if(allZero) {
        return 0;
    }

    return resultXOR == 0 ? n-1 : n;
}

int main() {
    vector<int> nums;
    while(true) {
        int n; cin >> n;
        if(n==-1)break;
        nums.push_back(n);
    }

    cout << longestSubsequence(nums) << endl;
    return 0;
}