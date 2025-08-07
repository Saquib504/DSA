#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
int f(int i, int prevInd, vector<int>&arr, vector<vector<int>>&memo) {
    if(i == arr.size()) return 0;

    if(memo[i][prevInd+1] != -1) return memo[i][prevInd+1];

    int len = 0 + f(i+1,prevInd, arr, memo);  //cannot take

    if(prevInd == -1 || arr[i] > arr[prevInd]) {
        len = max(len, 1 + f(i+1, i, arr, memo));
    }


    return memo[i][prevInd+1] = len;
}

// TABULATION METHOD
// int LIS(vector<int>& arr) {
//     int n = arr.size();

//     // memo[i][prevInd+1] because prevInd can be -1
//     vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

//     // Loop in reverse order (bottom-up)
//     for (int i = n - 1; i >= 0; i--) {
//         for (int prevInd = i - 1; prevInd >= -1; prevInd--) {

//             int notTake = memo[i + 1][prevInd + 1];
//             int take = 0;

//             if (prevInd == -1 || arr[i] > arr[prevInd]) {
//                 take = 1 + memo[i + 1][i + 1];  
//             }

//             memo[i][prevInd + 1] = max(take, notTake);
//         }
//     }

//     return memo[0][0];  
// }

// SPACE OPTIMIZATION
int LIS(vector<int>&arr) {
    int n = arr.size();

    vector<int>prev(n+1, 0), curr(n+1, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int prevInd = i-1; prevInd >= -1; prevInd--) {

            int notTake = prev[prevInd+1];
            int take = 0;

            if(prevInd == -1 || arr[i] > arr[prevInd]) {
                take = 1 + prev[i+1];
            }

            curr[prevInd+1] = max(notTake,take);
        }
        prev = curr;
    }
    return prev[0];
}

int main() {

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "The longest increasing subsequence : " << LIS(arr) << endl;
    return 0;
}