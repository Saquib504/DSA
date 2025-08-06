#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int buy, vector<int>&prices, int fee, vector<vector<int>>&memo) {
//     if(i == prices.size()) return 0;

//     if(memo[i][buy] != -1) return memo[i][buy];

//     if(buy == 1) {  // can buy on this day
//         return memo[i][buy] = max(-prices[i] + f(i+1, 0, prices, fee, memo), 0+f(i+1,1,prices,fee, memo));
//     }
    
//     // can sell on this day
//     return memo[i][buy] = max(-fee + prices[i]+f(i+1, 1,prices, fee, memo), 0+f(i+1,0,prices,fee, memo));
// }

// TABULATION METHOD
// int maxProfit(vector<int>&prices, int fee) {
//     int n = prices.size();

//     vector<vector<int>>memo(n+1, vector<int>(2, 0));

//     for(int i = n-1; i >= 0; i--) {
//         //can buy on this day
//         memo[i][1] = max(-prices[i]+memo[i+1][0], 0+memo[i+1][1]),

//         //can sell on this day
//         memo[i][0] = max(-fee + prices[i] + memo[i+1][1], 0 + memo[i+1][0]);
//     }
//     return memo[0][1];
// }

// SPACE OPTIMIZATION
int maxProfit(vector<int>&prices, int fee) {
    int n = prices.size();

    vector<int>prev(2,0), temp(2,0);

    for(int i = n-1; i >= 0; i--) {
        //can buy on this day
        temp[1] = max(-prices[i]+prev[0], 0+prev[1]),

        //can sell on this day
        temp[0] = max(-fee + prices[i] + prev[1], 0 + prev[0]);

        prev = temp;
    }
    return prev[1];
}

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    cout << "\n     The maximum profit after applying fee is " << maxProfit(prices, fee) << endl;cout<<endl;
    return 0;
}