#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int index, int target, vector<int>&wt, vector<int>&val, vector<vector<int>>&memo) {
//     if(index == 0) {
//         return (int)(target/wt[index])*val[index];
//     }

//     if(memo[index][target] != -1) return memo[index][target];

//     int notTake = 0 + f(index-1, target, wt, val, memo);

//     int take = INT_MIN;

//     if(wt[index] <= target)
//         take = val[index] + f(index, target - wt[index], wt, val, memo);


//     return memo[index][target] = max(notTake, take);
// }


// TABULATION METHOD
// int countVal(vector<int>&wt, vector<int>&val, int W) {
//     int n = wt.size();

//     vector<vector<int>>memo(n, vector<int>(W+1, 0));

//     for(int target = 0; target <= W; target++) {
//         memo[0][target] = (int)(target/wt[0])*(val[0]);
//     }

//     for(int i = 1; i <n; i++) {
//         for(int target = 0; target <= W; target++) {
//             int notTake = 0 + memo[i-1][target];
//             int take = INT_MIN;

//             if(wt[i] <= target)
//                 take = val[i] + memo[i][target - wt[i]];

//             memo[i][target] = max(notTake, take);
//         }
//     }
//     return memo[n-1][W];
// }

// SPACE OPTIMIZATION.  -> SC = O(2xW)
// int countVal(vector<int>&wt, vector<int>&val, int W) {
//     int n = wt.size();

//     vector<int>prev(W+1, 0);

//     for(int target = 0; target <= W; target++) {
//         prev[target] = (int)(target/wt[0])*(val[0]);
//     }

//     for(int i = 1; i <n; i++) {
//         vector<int>temp(W+1, 0);
//         for(int target = 0; target <= W; target++) {
//             int notTake = 0 + prev[target];
//             int take = INT_MIN;

//             if(wt[i] <= target)
//                 take = val[i] + temp[target - wt[i]];

//             temp[target] = max(notTake, take);
//         }
//         prev = temp;
//     }
//     return prev[W];
// }

// SPACE OPTIMIZATION-2:  ---->     SC = O(W)

int countVal(vector<int>&wt, vector<int>&val, int W) {
    int n = wt.size();

    vector<int>prev(W+1, 0);
    for(int target = 0; target <= W; target++) {
        prev[target] = ((int)(target / wt[0]))*val[0];
    }

    for(int i =1; i < n; i++) {
        for(int target = 0; target <= W; target++) {
            int notTake = 0 + prev[target];

            int take = INT_MIN;

            if(wt[i] <= target)
                take = val[i] + prev[target-wt[i]];


            prev[target] = max(notTake, take);
        }
    }
    return prev[W];
}

int main() {
    vector<int> wt = {2,4,6};
    vector<int> val = {5,11,13};
    int W = 10;

    cout << "The maximum value that the thief can steal is : " << countVal(wt, val, W) << endl;
    return 0;
}