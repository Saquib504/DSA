#include <iostream>
using namespace std;


// RECURSION + MEMOIZATION
// int f(int i, int tranNum, vector<int>&prices, int n, int k, vector<vector<int>>&memo) {
//     if(i == n || tranNum == 2*k) return 0;

//     if(memo[i][tranNum] != -1) return memo[i][tranNum];

//     if(tranNum % 2 == 0) {  //can buy on this day
//         return memo[i][tranNum] = max(-prices[i] + f(i+1, tranNum+1,prices,n,k, memo), 0+f(i+1, tranNum,prices,n,k, memo));
//     }

//     // can sell on this day
//     return memo[i][tranNum] = max(prices[i]+f(i+1, tranNum+1, prices,n,k, memo), 0+f(i+1, tranNum, prices, n, k, memo));
// }


// TABULATION METHOD
// int maxStock(vector<int>&prices, int k) {
//     int n = prices.size();

//     vector<vector<int>>memo(n+1, vector<int>(2*k+1, 0));
//     //Base case is handled in declaring the memo array.

//     for(int i = n-1; i >= 0; i--) {
//         for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {

//             if(tranNo % 2 == 0) {   //can buy on this day
//                 memo[i][tranNo] = max(-prices[i] + memo[i+1][tranNo+1], 0 + memo[i+1][tranNo]);
//             } 
//             else {  // can sell on this day
//                 memo[i][tranNo] = max(prices[i] + memo[i+1][tranNo+1], 0 + memo[i+1][tranNo]);
//             }
//         }
//     }
    

//     return memo[0][0];
// }


// SPACE OPTIMIMZATION
int maxStock(vector<int>&prices, int k) {
    int n = prices.size();

    vector<int>ahead(2*k+1, 0), temp(2*k+1, 0);
    //Base case is handled in declaring the memo array.

    for(int i = n-1; i >= 0; i--) {
        for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {

            if(tranNo % 2 == 0) {   //can buy on this day
               temp[tranNo] = max(-prices[i] + ahead[tranNo+1], 0 + ahead[tranNo]);
            } 
            else {  // can sell on this day
                temp[tranNo] = max(prices[i] + ahead[tranNo+1], 0 + ahead[tranNo]);
            }
        }
        ahead = temp;
    }
    

    return ahead[0];
}


int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;

    cout << "The maximum profit you can get from this week in k transactions is " << maxStock(prices, k) << endl;
}