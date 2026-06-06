#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//----------------------- 2574. Left and Right Sum Differences ------------------
//---------------------------------- My Solution --------------------------------
// TC -> O(n) for running through the array once, SC -> O(n) for storing the answer in a new array
vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n);

    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    int rightSum = totalSum - nums[0];
    answer[0] = abs(leftSum - rightSum);

    for(int i = 1; i < n; i++) {
        leftSum += nums[i-1];
        rightSum -= nums[i];
        answer[i] = abs(leftSum - rightSum);
    }
    return answer;
}

int main() {
    int n; cout << "Enter the number of elements: "; cin >> n;

    vector<int> nums;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        nums.push_back(x);
    }
    vector<int> result = leftRightDifference(nums);
    cout<<endl;
    cout << "Left Right Difference: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    return 0;
}