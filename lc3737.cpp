#include <iostream>
using namespace std;


//My Solution
//TC -> O(N^2)
//SC -> O(1)
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


//Better Solution
//TC -> O(N)
//SC -> O(N)
static int countMajoritySubarrays(vector<int>& nums, int target) {
    bias=nums.size()+1;
    int balance=bias;
    memset(cntB , 0, (2*bias)*sizeof(int));
    cntB[balance]=1;
    int ans=0, sum=0;
    
    for (int x : nums) {
        if (x==target) sum+=cntB[balance++];
        else sum-=cntB[--balance];
        
        cntB[balance]++;
        ans+=sum;
    }
    return ans;
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