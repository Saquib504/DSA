#include <iostream>
using namespace std;


int maxProduct(vector<int>& nums) {
    if(nums.size() < 2) return 0;

    sort(nums.begin(), nums.end());
    int n = nums.size();

    return (nums[n-1]-1)*(nums[n-2]-1);
}

int main() {
    vector<int> nums;

    cout << "\nEnter the elements: ";

    while(true) {
        int n;
        cin >> n;
        if(n == -1)break;
        else nums.push_back(n);
    }

    cout << "\nMaximum product of two elements in an array is: " << maxProduct(nums) << endl;

    return 0;
}