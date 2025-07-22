#include <iostream>
using namespace std;


// R E C U R S I O N + M E M O I Z A T I O N
//int f(int index, int target, vector<int>&coins, vector<vector<int>>&memo) {
//     if(index == 0){
//         if(target%coins[index] == 0){
//             return target/coins[index];
//         }else return 1e9;
//     }

//     if(memo[index][target] != -1) return memo[index][target];
    
//     int notTake = 0 + f(index-1, target, coins, memo);
//     int take = 1e9;

//     if(coins[index] <= target)
//         take = 1 + f(index, target - coins[index], coins, memo);


//     return memo[index][target] = min(notTake, take);
// }

// T A B U L A T I O N - M E T H O D
// int coinChange(vector<int>&coins, int amount) {
//     int n = coins.size();

//     vector<vector<int>>memo(n, vector<int>(amount+1, 0));

//     for(int target = 0; target <= amount; target++) {
//         if(target % coins[0] == 0){
//             memo[0][target] = target / coins[0];
//         }else memo[0][target] = 1e9;
//     }

//     for(int i = 1; i < n; i++) {
//         for(int target = 0; target <= amount; target++) {
//             int notTake = 0 + memo[i-1][target];

//             int take = 1e9;

//             if(coins[i] <= target) take = 1 + memo[i][target - coins[i]];

//             memo[i][target] = min(notTake, take);
//         }
//     }
//     return memo[n-1][amount];
// }

// S P A C E - O P T I M I Z A T I O N
int coinChange(vector<int>&coins, int amount) {
    int n = coins.size();

    vector<int>prev(amount+1, 0);
    vector<int>temp(amount+1, 0);
    
    for(int target = 0; target <= amount; target++) {
        if(target% coins[0] == 0) {
            prev[target] = target / coins[0];
        }else prev[target] = 1e9;
    }

    for(int i = 1; i < n; i++) {
        for(int target = 0; target <= amount; target++) {
            int notTake = 0 + prev[target];
            int take = INT_MAX;
            if(coins[i] <= target) take = 1 + temp[target - coins[i]];
            temp[target] = min(notTake, take);
        }
        prev = temp;
    }
    int ans = prev[amount];
    if(ans == 1e9) return -1;
    else return ans;
}



int main() {
    vector<int>coins = {7,5};
    int T = 11;
    
    cout << "The minimum number of coins required are : " << coinChange(coins, T) << endl;
    return 0;
}