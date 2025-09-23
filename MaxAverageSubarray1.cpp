#include <iostream>
using namespace std;
#include <vector>

double findMaxAverage(vector<int>& nums, int k) {
    int l=0,r=0;
    double sum=0;
    while(r<k){
        sum+=nums[r++];
    }
    double maxi = sum;
    while(r<nums.size()){
        sum+=nums[r];
        sum-=nums[r-k];
        maxi = max(maxi,sum);
        r++;
    }
    return maxi/k;
}


int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k  = 4;

    cout << findMaxAverage(nums, k) << endl;

    return 0;
}