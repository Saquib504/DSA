#include <iostream>
using namespace std;
#define ll long long

// RECURSION + MEMOIZATION
// int f(int i, int j, int isTrue, string&word, vector<vector<vector<int>>>&memo) {
//     if(i > j) return 0;
//     if(i == j) {
//         if(isTrue) return word[i] == 'T';
//         else return word[i] == 'F';
//     }

//     if(memo[i][j][isTrue] != -1) return memo[i][j][isTrue];

//     int ways = 0;

//     for(int ind = i+1; ind <= j-1; ind += 2) {
//         int lT = f(i, ind-1, 1, word, memo);
//         int lF = f(i, ind-1, 0, word, memo);
//         int rT = f(ind+1, j, 1, word, memo);
//         int rF = f(ind+1, j, 0, word, memo);

//         if(word[ind] == '&') {
//             if(isTrue) {
//                 ways += lT*rT;
//             }
//             else {
//                 ways += lT*rF + lF*rT + lF*rF;
//             }
//         }
//         else if(word[ind] == '|') {
//             if(isTrue) {
//                 ways += lT*rT + lT*rF + lF*rT;
//             }
//             else {
//                 ways += lF*rF;
//             }
//         }
//         else {
//             if(isTrue) {
//                 ways += lT*rF + lF*rT;
//             }
//             else {
//                 ways += lT*rT + lF*rF;
//             }
//         }
//     }
//     return memo[i][j][isTrue] = ways;
// }


int getTrueCount(string&exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            if (i > j) continue;
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {
                        if (isTrue) ways = ways + (lT * rT);
                        else ways = ways + (lF * rT)  + (lT * rF)  + (lF * rF) ;
                    }
                    else if (exp[ind] == '|') {
                        if (isTrue) ways = ways + (lF * rT) + (lT * rF) + (lT * rT);
                        else ways = ways + (lF * rF);
                    }
                    else {
                        if (isTrue) ways = ways + (lF * rT) + (lT * rF);
                        else ways = ways + (lF * rF) + (lT * rT);
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}


int main() {

    string word = "T^F|T&F^T|F";

    cout << "The total number of ways in which we can get true is " << getTrueCount(word) << endl;

    return 0;
}