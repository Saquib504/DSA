#include <iostream>
using namespace std;

//Recursion + Memoization
// bool f(int index, vector<int>&arr, int target,  vector<vector<int>>&memo) {
//     if(target == 0) return true;

//     if(index == 0) return(arr[index] == target);

//     if(memo[index][target] != -1) return memo[index][target];

//     bool notTaken = f(index - 1, arr, target, memo);

//     bool taken = false;
//     if(arr[index] <= target) taken = f(index - 1, arr, target - arr[index], memo);

//     return memo[index][target] = notTaken || taken;
// }
// bool subsetSumToK2(vector<int> &arr) {
//     int n = arr.size();

//     int totalSum = 0;
//     for(int i = 0; i < n; i++)totalSum += arr[i];

//     if(totalSum % 2) return false;

//     vector<vector<int>>memo(n+1, vector<int>(totalSum + 1, -1));

//     return f(n-1, arr, totalSum, memo);
// }




//Tabulation Method
// bool subsetSumToK2(vector<int> &arr) {
//     int n = arr.size();

//     int totalSum = 0;
//     for(int i = 0; i < n; i++)totalSum += arr[i];

//     if(totalSum % 2) return false;

    
//     vector<vector<bool>>memo(n, vector<bool>(totalSum+1, false));

//     //Base Case-1: if the target == 0, return true;
//     for(int i = 0; i < n; i++) {
//         //memo[index][target]
//         memo[i][0] = true;
//     }

//     //Base Case-2: if index == 0, and a[index] == target, return true;
//     if(arr[0] <= totalSum) memo[0][arr[0]] = true;

//     for(int i = 1; i < n; i++) {
//         for(int j = 1; j <= totalSum; j++) {

//             bool notTaken = memo[i-1][j];

//             bool taken = false;

//             if(arr[i] <= j) {
//                 taken = memo[i-1][j - arr[i]];
//             }

//             memo[i][j] = notTaken || taken;
//         }
//     }
//     return memo[n-1][totalSum];
// }



//Space Optimization

bool func(int n, vector<int>&arr, int target) {
    vector<bool>prev(target+1, false);
    //Base Case-1:
    prev[0] = true;

    //Base Case-2:
    if(arr[0] <= target) prev[arr[0]] = true;

    for(int i = 1; i < n; i++) {
        vector<bool>temp(target+1, false);
        temp[0] = true;

        for(int j = 1; j <= target; j++) {
            bool notTaken = prev[j];

            bool taken = false;
            if(arr[i] <= j) {
                taken = prev[j - arr[i]];
            }

            temp[j] = notTaken || taken;
        }
        prev = temp;
    }

    return prev[target];
}

bool subsetSumToK2(vector<int> &arr) {
    int n = arr.size();

    int totalSum = 0;
    for(int i = 0; i < n; i++)totalSum += arr[i];

    if(totalSum % 2) return false;

    return func(n, arr, totalSum/2);
}

int main() {
    vector<int> arr = {2,3,3,3,4,5};
    //int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK2(arr))
        cout << "Subset with the given target found\n";
    else
        cout << "Subset with the given target not found\n";

    return 0;
}
