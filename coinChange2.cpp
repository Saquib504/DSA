#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int index, int target, vector<int>&coins, vector<vector<int>>&memo) {
//     if(target < 0) return 0;

//     if(target == 0) return 1;

//     if(index == 0) {
//         if(target % coins[index] == 0) return 1;
//         return 0;
//     }

//     if(memo[index][target] != -1) return memo[indx][target];

//     int notTake = f(index-1, target, coins);
//     int take = 0;

//     if(target >= coins[index])
//         take = f(index, target - coins[index], coins);

//     return memo[index][target] = notTake + take;
// }



// TABULATION METHOD
// int countWays(vector<int>&coins, int x) {
//     int n = coins.size();
//     vector<vector<int>>memo(n, vector<int>(x+1, 0));

//     for(int target = 0; target <= x; target++) {
//         if(target % coins[0] == 0) {
//             memo[0][target] = 1;
//         }
//         else memo[0][target] = 0;
//     }

//     for(int i =1; i < n; i++) {
//         for(int target = 0; target <= x; target++) {
//             int notTake = memo[i-1][target];

//             int take =0;
//             if(coins[i] <= target) 
//                 take = memo[i][target-coins[i]];


//             memo[i][target] = notTake+take;
//         }
//     }

//     int ans = memo[n-1][x];
//     if(ans == 0) return 0;
//     return ans;
// }



// SPACE OPTIMIZATION
int countWays(vector<int>&coins, int x) {
    int n = coins.size();
    vector<int>prev(x+1, 0);
    for(int target = 0; target <= x; target++) {
        if(target % coins[0] == 0) {
            prev[target] = 1;
        }
        else prev[target] = 0;
    }

    for(int i =1; i < n; i++) {
        vector<int>temp(x+1,0);
        for(int target = 0; target <= x; target++) {
            int notTake = prev[target];

            int take =0;
            if(coins[i] <= target) 
                take = temp[target-coins[i]];


            temp[target] = notTake+take;
        }
        prev = temp;
    }
    int ans = prev[x];
    if(ans == 0) return 0;
    return ans;
}

int main() {
    vector<int> coins = {1,2,3};
    int x = 4;

    cout << "The number of ways to get " << x << " is " << countWays(coins, x) << endl;
    return 0;
}