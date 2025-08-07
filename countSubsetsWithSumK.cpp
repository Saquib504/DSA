#include <iostream>
using namespace std;

// R E C U R S I O N + M E M O I Z A T I O N :
// int f(int index, int target, vector<int>&arr, vector<vector<int>>&memo) {
//     if(target == 0) return 1;
//     if(index == 0) {
//         if(arr[index] == target) return 1;
//         return 0;
//     }
//     if(memo[index][target] != -1) return memo[index][target];

//     int notPick = f(index-1, target, arr, memo);
//     int pick = 0;
//     if(arr[index] <= target) pick = f(index-1, target - arr[index], arr, memo);

//     return memo[index][target] = notPick + pick;
// }

// T A B U L A T I O N - M E T H O D
// int countSubsetsWithSumK(vector<int>&arr, int k) {
//     int n = arr.size();

//     vector<vector<int>>memo(n, vector<int>(k+1, 0));

//     //Base Case-1: if target == 0
//     for(int i = 0; i < n; i++) {
//         memo[i][0] = 1;
//     }

//     //Base case-2; if index ==0
//     if(arr[0] <= k) memo[0][arr[0]] = 1;

//     for(int i =1; i < n; i++) {
//         for(int j = 1; j <= k; j++) {
//             int notPick = memo[i-1][j];
//             int pick = 0;
//             if(arr[i] <= j) pick = memo[i-1][j - arr[i]];

//             memo[i][j] = notPick + pick;
//         }
//     }
//     return memo[n-1][k];
    
// }


//Space Optimization
int countSubsetsWithSumK(vector<int>&arr, int k) {
    int n = arr.size();

    vector<int>prev(k+1, 0);
    //Base Case-1:
    prev[0] = 1;

    //Base Case-2:
    if(arr[0] <= k) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++) {
        vector<int>curr(k+1, 0);
        curr[0] = 1;

        for(int j = 1; j <= k; j++) {
            int notPick = prev[j];
            int pick = 0;

            if(arr[i] <= j) pick = prev[j-arr[i]];

            curr[j] = notPick + pick;
        }
        prev = curr;
    }
    return prev[k];
}

int main() {
    vector<int> arr = {1,1,4,5};
    int k = 5;
    cout << "Total subsets with sum " << k << " is : " << countSubsetsWithSumK(arr, k) << endl;
    return 0;
}