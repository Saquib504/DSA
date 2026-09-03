#include <iostream>
using namespace std;

bool uniformArray(vector<int>& nums1) {
    int minOdd = INT_MAX, minEven = INT_MAX;

    for(auto num : nums1) {
        if(num % 2 == 0) minEven = min(minEven, num);
        else minOdd = min(minOdd, num);
    }

    if(minOdd < minEven || minOdd == INT_MAX || minEven == INT_MAX) return true;
    return false;
}

int main() {
    vector<int> nums;
    cout << "Enter nums: ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
    }

    return uniformArray(nums) == true ? 1 : 0;
}