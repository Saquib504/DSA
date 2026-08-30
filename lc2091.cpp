#include <iostream>
using namespace std;

int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    int minIDX = 0, maxIDX = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] < nums[minIDX]) minIDX = i;
        if(nums[i] > nums[maxIDX]) maxIDX = i;
    }

    int left = min(minIDX, maxIDX);
    int right = max(minIDX, maxIDX);

    int case1 = right + 1;
    int case2 = n-left;
    int case3 = (left + 1) + (n - right);

    return min({case1, case2, case3});
}

int main() {
    vector<int> nums;
    cout << "Enter elements : "; 
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cout << "Minimum number of deletions it would take to remove both the minimum and maximum element from the array is : " << minimumDeletions(nums) << endl;
    return 0; 
}