#include <iostream>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n <= 1) return;

    k %= n;

    auto Reverse = [&](int i, int j) {
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    };
    Reverse(0, n-1);
    Reverse(0,k-1);
    Reverse(k, n-1);
}
