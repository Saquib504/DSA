#include <iostream>
#include <unordered_set>
using namespace std;

int missingInteger(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> seen(nums.begin(), nums.end());
    int sum = nums[0];

    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i-1] + 1) sum += nums[i];
        else break;
    }

    while(seen.count(sum)) {
        sum++;
    }

    return sum;
}


int main() {
    vector<int> nums;
    cout << "Enter the elements in the nums array(input -1 for breaking): ";
    while(true) {
        int n ; cin >> n;
        if(n == -1)break;
        else nums.push_back(n);
    }

    cout << "Missing integer which is greater than or equal to the sum of the longest sequential prefix :  " << missingInteger(nums) << endl;
    return 0;
}