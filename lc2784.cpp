#include <iostream>
using namespace std;



    bool isGood(vector<int>& nums) {
        int n = nums.size()-1;
        if(n == 0) return 0;
        int hash[201] = {0};


        for(int num : nums) {
            if(++hash[num] == 2 && num != n) return 0;
        }

        for(int num = 1; num <= n-1; num++) {
            if(hash[num] != 1) return 0;
        }

        return hash[n] == 2;
    }

int main() {
    vector<int> nums = {1, 1,2,3,4,5,6,6};
    cout << isGood(nums) << endl; // Output: false
    return 0;
}