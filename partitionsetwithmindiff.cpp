#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Tabulation Method
// int partitionsetmindiff(vector<int>&arr) {
//     int n = arr.size();
//     int totalSum = 0;
//     for(int i = 0; i < n ;i++)totalSum += arr[i];

//     vector<vector<bool>>memo(n, vector<bool>(totalSum+1, false));

//     for(int i =0; i<n; i++) memo[i][0] = true;

//     if(arr[0] <= totalSum) memo[0][arr[0]] = true;

//     for(int i = 1; i < n; i++) {
//         for(int j = 1; j <= totalSum; j++) {
//             bool notTaken = memo[i-1][j];

//             bool taken = false;

//             if(arr[i] <= j) taken = memo[i-1][j - arr[i]];


//             memo[i][j] = notTaken || taken;
//         }
//     }

//     int mini = 1e9;
//     for(int s1 = 0; s1 <= totalSum/2; s1++) {
//         if(memo[n-1][s1]) {
//             int s2 = totalSum - s1;
//             mini = min(mini, abs(s1 - s2));
//         }
//     }
//     return mini;
// }


//Space Optimization
int minSubsetSumDifference(vector<int>& arr, int n) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Initialize a boolean vector 'prev' to represent the previous row of the DP table
    vector<bool> prev(totSum + 1, false);

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    prev[0] = true;

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        prev[arr[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a boolean vector 'cur' to represent the current row of the DP table
        vector<bool> cur(totSum + 1, false);
        cur[0] = true;

        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }

        // Set 'cur' as the 'prev' for the next iteration
        prev = cur;
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (prev[i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}



int main() {
    vector<int>arr = {2,3,7};
    int n = arr.size();
    cout << "The min absulute diffrence in two susets is " << minSubsetSumDifference(arr, n) << endl;
    return 0;
    
}