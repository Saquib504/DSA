#include <iostream>
using namespace std;

int solve(int n) {
    int temp = n;
    int sum = 0;
    while(temp) {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    return sum;
}
int smallestIndex(vector<int>& nums) {
    int n = nums.size();
    int minIDX = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if(solve(nums[i]) == i) {
            minIDX = min(minIDX, i);
        }
    }

    return (minIDX == INT_MAX) ? -1 : minIDX;
}

int main() {
    vector<int> nums;
    cout << "Enter elements of nums : ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cout << "Smallest Index With Digit Sum Equal to Index : " << smallestIndex(nums) << endl;
}