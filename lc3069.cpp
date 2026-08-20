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

int main() {
    int n;
}