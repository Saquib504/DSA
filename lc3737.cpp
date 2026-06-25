#include <iostream>
using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target) {
    int n = nums.size();
    int cnt = 0;

    for(int l = 0; l < n; l++) {
        int freq = 0;
        for(int r = l; r < n; r++) {
            if(nums[r] == target)freq++;
            int len = r-l+1;

            if(freq > len/2) cnt++;
        }
    }
    return cnt;
}


int main() {
    int n; cout << "Enter number of elements: "; cin >> n;
    vector<int> nums(n);
    cout << "Enter each element: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target; cout << "\nEnter the target element: "; cin >> target;
    int ans = countMajoritySubarrays(nums, target);
    

    cout << "Number of subarrays :" << ans << endl;

    return 0;
}