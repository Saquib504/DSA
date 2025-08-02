#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int buy, vector<int>&prices,vector<vector<int>>&memo) {
//     if(i == prices.size()) return 0;

//     if(memo[i][buy] != -1) return memo[i][buy];

//     int profit = 0;

//     if(buy) {
//         profit = max(-prices[i] + f(i+1, 0, prices,memo), 0 + f(i+1, 1, prices,memo));
//     }
//     else {
//         profit = max(prices[i] + f(i+1, 1, prices, memo), 0 + f(i+1, 0, prices, memo));
//     }
//     return memo[i][buy] = profit;
// }


// TABULATION METHOD
// int maxStock(vector<int>&prices) {
//     int n = prices.size();

//     vector<vector<int>>memo(n+1, vector<int>(2, 0));
//     int profit = 0;

//     for(int ind = n-1; ind>= 0; ind--) {
//         for(int buy = 0; buy <= 1; buy++) {
//             if (buy == 0) { // We can buy the stock
//                 profit = max(0 + memo[ind + 1][0], -prices[ind] + memo[ind + 1][1]);
//             }

//             if (buy == 1) { // We can sell the stock
//                 profit = max(0 + memo[ind + 1][1], prices[ind] + memo[ind + 1][0]);
//             }
//             memo[ind][buy] = profit;
//         }
//     }

//     return memo[0][0];
// }


// SPACE OPTIMIZATION
int maxStock(vector<int>&prices) {
    int n = prices.size();

    vector<int>ahead(n+1, 0), temp(n+1, 0);;
    int profit = 0;

    for(int ind = n-1; ind>= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -prices[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], prices[ind] + ahead[0]);
            }
            temp[buy] = profit;
        }
        ahead = temp;
    }

    return ahead[0];
}


int main() {

    vector<int>prices = {7,1,5,3,6,4};

    cout << "The maximum profit you made throughout the week is " << maxStock(prices) << endl;
    return 0;
}