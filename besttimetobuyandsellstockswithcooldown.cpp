#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int buy, vector<int>&prices, vector<vector<int>>&memo) {
//     if(i >= prices.size()) return 0;
//     if(memo[i][buy] != -1) return memo[i][buy];

//     if(buy == 0) {
//         return memo[i][buy] = max(-prices[i]+f(i+1, 1, prices, memo), 0+f(i+1,0,prices, memo));
//     }

//     return memo[i][buy] = max(prices[i]+f(i+2,0,prices, memo), 0+f(i+1, 1, prices, memo));
// }

// TABULATION METHOD
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<int>front1(2,0);
    vector<int>front2(2,0);
    vector<int>curr(2,0);

    for(int i = n-1; i >= 0; i--) {

        curr[1] = max(-prices[i]+front1[0],0+front1[1]);

        curr[0] = max(prices[i]+front2[1], 0+front1[0]);

        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}



int main() {
    vector<int>prices = {1,2,3,0,2};

    cout << "The maximum profit to get is " << maxProfit(prices) << endl;
    return 0;
}