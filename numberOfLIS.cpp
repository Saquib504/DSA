#include <iostream>
using namespace std;

int numberOfLIS(vector<int>&nums) {
    int n = nums.size();
    int maxLIS = 0, numOFLIS = 0;

    vector<int>count(n,1), memo(n,1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && 1 + count[j] > count[i]) {
                count[i] = 1 + count[j];
                memo[i] = memo[j];   //inherit
            }

            else if(nums[i] > nums[j] && 1 + count[j] == count[i]) {
                memo[i] = memo[i] + memo[j]; //increase
            }
        }
        maxLIS = max(maxLIS, count[i]);
    }

    for(int i = 0; i < n; i++) {
        if(count[i] == maxLIS) numOFLIS += memo[i];
    }
    return numOFLIS;
}

int main() {
    vector<int>nums = {1,3,5,4,7};

    cout << "The number of longest increasing subsequences id : " << numberOfLIS(nums) << endl;

    return 0;
}