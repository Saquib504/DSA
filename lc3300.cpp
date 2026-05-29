#include <iostream>
#include <vector>
using namespace std;



int minElement(vector<int>& nums) {
    int minSum = 1e9;

    for(int num : nums) {
        int sum = 0;

        while(num > 0) {
            sum += num%10;
            num /= 10;
        }

        minSum = min(minSum, sum);
    }
    return minSum;
}


int main() {
    cout << endl;
    cout << "LC3300: Minimum Sum of Digits in an Array" << endl;
    int n; cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Minimum sum of digits in the array: " << minElement(nums) << endl;
    return 0;
}