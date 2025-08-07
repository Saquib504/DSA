#include<iostream>
using namespace std;


// RECURSION + MEMOIZATION
// int f(int i, int buy, int cap, vector<int>&prices, vector<vector<int>>&memo) {
//     if(cap == 0) return 0;
//     if(i == prices.size()) return 0;
//     if(memo[i][buy] != -1) return memo[i][buy];
//     int profit;
//     if(buy == 0) {  //time to sell
//         profit = max(prices[i]+ f(i+1,1,cap-1, prices,memo), 0 + f(i+1, 0, cap, prices,memo));
//     }
//     else {  //time to buy
//         profit = max(-prices[i]+f(i+1,0,cap,prices,memo), 0+f(i+1,1,cap,prices,memo));
//     }
//     return memo[i][buy] = profit;
// }

// TABULATION METHOD
// int maxStock(vector<int>&prices, int Capacity) {
//     int n = prices.size();

//     vector<vector<vector<int>>>memo(n+1, vector<vector<int>>(2, vector<int>(Capacity, 0)));

//     for(int i = n-1; i >= 0; i--) {
//         for(int buy = 0; buy <= 1; buy++) {
//             for(int cap = 1; cap <= Capacity; cap++) {
//                 if(buy == 0) {  //can sell on this day
//                     memo[i][buy][cap] = max(prices[i]+memo[i+1][1][cap-1], 0+memo[i+1][0][cap]);
//                 }
//                 if(buy == 1) {  //can buy on this day
//                     memo[i][buy][cap] = max(-prices[i]+memo[i+1][0][cap], 0+memo[i+1][1][cap]);
//                 }
//             }
//         }
//     }
//     return memo[0][1][2];
// }

// SPACE OPTIMIZATION
int maxStock(vector<int>&prices) {
    int n = prices.size();

    vector<vector<int>>after(2, vector<int>(3, 0));
    vector<vector<int>>temp(2, vector<int>(3, 0));

    for(int i = n-1; i >= 0; i--) {
    for(int buy = 0; buy <= 1; buy++) {
        for(int cap = 1; cap <= 2; cap++) {
            if(buy == 0) {  //can sell on this day
                temp[buy][cap] = max(prices[i]+after[1][cap-1], 0+after[0][cap]);
            }
            if(buy == 1) {  //can buy on this day
                temp[buy][cap] = max(-prices[i]+after[0][cap], 0+after[1][cap]);
            }
        }
        after = temp;
    }
    }
    return after[1][2];
}



int main() {
    vector<int>prices = {3,3,5,0,0,3,1,4};

    cout << "The maximum profit you can get is " << maxStock(prices) << endl;
    return 0;
}