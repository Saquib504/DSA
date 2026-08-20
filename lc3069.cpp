#include <iostream>
#include <vector>
using namespace std;


vector<int> resultArray(vector<int>& nums) {
    int n = nums.size();
    queue<int> arr1, arr2;
    vector<int> result;
    arr1.push(nums[0]);
    arr2.push(nums[1]);

    for(int i = 2; i < n; i++) {
        if(arr1.back() > arr2.back()) {
            arr1.push(nums[i]);
        } else {
            arr2.push(nums[i]);
        }
    }

    while(!arr1.empty()) {
        result.push_back(arr1.front());
        arr1.pop();
    }

    while(!arr2.empty()) {
        result.push_back(arr2.front());
        arr2.pop();
    }

    return result;
}

//Better Solution
//Optimized Space Complexity

vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1 = {nums[0]};
    vector<int> arr2 = {nums[1]};

    for (size_t i = 2; i < nums.size(); ++i) {
        if (arr1.back() > arr2.back()) {
            arr1.push_back(nums[i]);
        } else {
            arr2.push_back(nums[i]);
        }
    }

    // Concatenate arr2 onto the end of arr1
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}