#include <iostream>
using namespace std;


// RECURSION + MEMOIZATION
// int f(int index, int N, vector<int>&price, vector<vector<int>>&memo) {
//     if(index == 0) {
//         return price[0]*N;
//     }

//     if(memo[index][N] != -1) return memo[index][N];

//     int notTake = 0 + f(index-1, N, price, memo);

//     int take = INT_MIN;
//     if(index+1 <= N)
//         take = price[index] + f(index, N - index-1 ,price, memo);

//     return memo[index][N] = max(notTake, take);
// }

// TABULATION METHOD
// int getProfit(vector<int>&price, int N) {
//     int n = price.size();

//     vector<vector<int>>memo(n, vector<int>(N+1, 0));

//     for(int target = 0; target <= N; target++) {
//         memo[0][target] = target*price[0];
//     }

//     for(int i = 1; i < n ;i++) {
//         for(int target = 0; target <= N; target++) {
//             int notTake = 0 + memo[i-1][target];
//             int take = INT_MIN;

//             if(i+1 <= target)
//                 take = price[i] + memo[i][target - i-1];

//             memo[i][target] = max(notTake, take);
//         }
//     }
//     return memo[n-1][N];

// }

// SPACE OPTIMIZATION
int getProfit(vector<int>&price, int N) {
    int n = price.size();

    vector<int>prev(N+1, 0);
    for(int target = 0; target <= N; target++) {
        prev[target] = target*price[0];
    }

    for(int i = 1; i < n; i++) {
        for(int target = 0; target <= N; target++) {
            int notTake = 0 + prev[target];
            int take = INT_MIN;

            if(i+1 <= target)
                take = price[i] + prev[target - i - 1];

            prev[target] = max(notTake, take);
        }
    }
    return prev[N];
}



int main() {
    vector<int>price = {2,5,7,8,10};
    int N = 5;

    cout << "Maximum profit by selling pieces of rod is " << getProfit(price, N) << endl;
    return 0;
}