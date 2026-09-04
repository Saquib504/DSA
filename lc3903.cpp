#include <iostream>
using namespace std;

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 1) return 0;
    vector<int> prefixMax(n), suffixMin(n);
    prefixMax[0] = nums[0];
    suffixMin[n-1] = nums[n-1];

    for(int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i-1], nums[i]);
        suffixMin[n-i-1] = min(suffixMin[n-i], nums[n-i-1]);
    }

    int result = -1;

    for(int i = 0 ; i < n; i++) {
        if(prefixMax[i] - suffixMin[i] <= k) {
            result = i;
            break;
        }
    }

    return result == -1 ? -1 : result;
}
int firstStableIndexOP(vector<int>& nums, int k) {
    int n = nums.size();

    int prefixMax = nums[0];
    vector<int> suffixMin(n);
    int result = -1;

    for(int i = n-2; i >= 0; i--) {
        suffixMin[i] = min(suffixMin[i+1], nums[i]);
    }

    for(int i = 1; i < n; i++) {
        prefixMax = max(prefixMax, nums[i]);

        if(prefixMax - suffixMin[i] <= k) {
            result = i;
            break;
        }
    }

    return result == -1 ? -1 : result;
}


int main() {
    vector<int> nums; int k;
    cout << "Enter the nums array: ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cout << "Enter the value of k: "; cin >> k;

    int result = firstStableIndex(nums, k);
    if(result == -1) {
        cout << "No such stable index exist in the nums array!\n";
    } else {
        cout << "The stable index is " << result << "\n";
    }

    return 0;
}