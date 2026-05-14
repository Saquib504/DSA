#include <iostream>
#include <vector>
using namespace std;



int countElements(vector<int>& nums) {
    int n = nums.size();

    //check if all elements are equal
    bool allEqual = true;
    for(int i = 0; i < n-1; i++) {
        if(nums[i] != nums[i+1]) allEqual = false;
    }
    
    //return 0 if all equal
    if(allEqual) return 0;
    
    int minEle = *min_element(begin(nums), end(nums));
    int maxEle = *max_element(begin(nums), end(nums));
    int count_min = 0, count_max = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == minEle)count_min++;
        else if(nums[i] == maxEle)count_max++;
        else continue;
    }

    return n - count_min - count_max;
}


int main() {
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3};
    cout << countElements(nums) << endl; // Output: 2
    return 0;
}