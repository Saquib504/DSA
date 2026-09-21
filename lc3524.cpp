#include <iostream>
using namespace std;

vector<long long> resultArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> result(k, 0);
    vector<long long> prevCount(k, 0);

    for(int i = 0; i < n; i++) {
        vector<long long> currCount(k, 0);

        int currEleCount = nums[i] % k;
        currCount[currEleCount]++;

        for(int x = 0; x <= k-1; x++) {
            int newX = ((long long)x * nums[i] % k) % k;

            currCount[newX] += prevCount[x];
        }

        prevCount = move(currCount);

        for(int x = 0; x <= k-1; x++) {
            result[x] += prevCount[x];
        }
    }

    return result;
}