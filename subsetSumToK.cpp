#include <iostream>
using namespace std;

//Recursion + Memoization
// bool f(int ind, int target, vector<int>&arr, vector<vector<int>>&memo) {
//     if(target == 0) return true;
//     if(ind == 0) return arr[0] == target;

//     if(memo[ind][target] != -1) return memo[ind][target];

//     bool notTaken = f(ind-1, target, arr, memo);

//     bool taken = false;
//     if(arr[ind] <= target) {
//         taken = f(ind-1, target - arr[ind], arr, memo);
//     }


//     return memo[ind][target] = notTaken || taken;
// }

//Tabulation Method
// bool subsetSumToK(int n, int k, vector<int>&arr) {
//     vector<vector<int>>memo(n+1, vector<int>(k+1, -1));

//     //Base Case - 1:

//     for(int i = 0; i < n; i++) {
//         memo[i][0] = true;
//     }

//     if(arr[0] <= k) {
//         memo[0][arr[0]] = true;
//     }

//     for(int ind = 1; ind <= n; ind++) {
//         for(int target = 1; target <= k; target++) {
//             bool notTaken = memo[ind-1][target];

//             bool taken = false;

//             if(arr[ind] < target) 
//                 taken = memo[ind-1][target - arr[ind]];

//             memo[ind][target] = taken || notTaken;
//         }
//     }

//     return memo[n-1][k];
// }


bool subsetSumToK(int n, int k, vector<int>&arr) {
    vector<bool>prev(k+1, false);
    prev[0] = true;

    for(int ind = 1; ind <= n; ind++) {
        vector<bool>current(k+1, false);
        current[0] = true;

        for(int target = 1; target <= k; target++) {
            bool notTaken = prev[target];

            bool taken = false;
            if(arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            current[target] = notTaken || taken;
        }
        prev = current;
    }
    return prev[k];
}


int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found\n";
    else
        cout << "Subset with the given target not found\n";

    return 0;
}
