#include <iostream>
using namespace std;

// Q.3(Medium) Count Bowl Subarrays
// TC -> O(N^3)
// int maxInBetween(int l, int r, vector<int>&nums) {
//     int maxELE= INT_MIN;
//     for(int i = l+1; i < r; i++) {
//         if(nums[i] > maxELE){
//             maxELE = nums[i];
//         }
//     }
//     return maxELE;
// }
// long long bowlSubarrays(vector<int>& nums) {
//     int n = nums.size();
//     int cnt = 0;

//     for(int l = 0; l < n-2; l++) {
//         for(int r = l+2; r < n; r++) {
//             int minSide = min(nums[l], nums[r]);
//             int maxInBtwn = maxInBetween(l, r, nums);
//             if(minSide <= maxInBtwn)continue;
//             else cnt++;
//         }
//     }
//     return cnt;
// }


//optimised solution.      ----> O(N)
// long long countBowlSubarrays(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> leftGreater(n, -1), rightGreater(n, n);

//     // Monotonic decreasing stack for left greater
//     stack<int> st;
//     for (int i = 0; i < n; i++) {
//         while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
//         if (!st.empty()) leftGreater[i] = st.top();
//         st.push(i);
//     }

//     // Clear and reuse stack for right greater
//     while (!st.empty()) st.pop();
//     for (int i = n-1; i >= 0; i--) {
//         while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
//         if (!st.empty()) rightGreater[i] = st.top();
//         st.push(i);
//     }

//     long long cnt = 0;
//     // For each possible "middle" index i, check if it can form bowls
//     for (int i = 0; i < n; i++) {
//         int l = leftGreater[i];
//         int r = rightGreater[i];
//         if (l != -1 && r != n && r - l > 1) {
//             cnt++; // (l, r) is a valid bowl
//         }
//     }
//     return cnt;
// }




//Q.1 (Easy) Minimum Operations to Equalize Array

// int minOperations(vector<int>&nums) {
//     int n = nums.size();
//     int target = nums[0];

//     //if all elements are same in the nums array
//     if (all_of(nums.begin(), nums.end(), [&](int x){ return x == nums[0]; }))
//         return 0;

    
//     //the elements are not same
//     return 1;
// }

//Q.2(Medium) Minimum Operations to Tranform String
//Intuition : we can keep the track of the max number of steps required for a character to convert it into 'a'

int minOperations(string&s) {
    string severus = s;

    int ans = 0;
    for(auto ch : severus) {
        int steps = (26 - (ch - 'a'))%26;

        ans = max(ans, steps);
    }
    return ans;
}

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";

    cout << minOperations(s) << endl;

    return 0;

}

//i fucked up pretty badly in this contest like for real, i got in trouble dude.so fucked up right now dude
//did nothing special today