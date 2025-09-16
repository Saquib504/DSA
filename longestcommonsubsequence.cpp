#include <iostream>
#include <string>
using namespace std;


// RECURSION + MEMOIZATION
// int f(int i, int j, string&s1, string&s2, vector<vector<int>>&memo) {
//     if(i < 0 || j < 0) {
//         return 0;
//     }
//     if(memo[i][j] != -1) return memo[i][j];

//     if(s1[i] == s2[j]) {
//         return memo[i][j] = 1 + f(i-1, j-1, s1, s2, memo);
//     }

//     return memo[i][j] = max(f(i-1, j, s1, s2, memo), f(i, j-1, s1, s2, memo));
// }


// TABULATION METHOD
// int findLCS(string&s1, string&s2) {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>>memo(n+1, vector<int>(m+1, 0));

//     for(int i =1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             if(s1[i-1] == s2[j-1]) {
//                 memo[i][j] = 1 + memo[i-1][j-1];
//             } else {
//                 memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
//             }
//         }
//     }
//     return memo[n][m];

// }


// SPACE OPTIMIZATION
int findLCS(string&s1, string&s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0);

    for(int i =1; i <= n; i++) {
        vector<int>temp(m+1, 0);
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                temp[j] = 1 + prev[j-1];
            } else {
                temp[j] = max(prev[j], temp[j-1]);
            }
        }
        prev = temp;
    }
    return prev[m];

}

int main() {
    string s1 = "abcde12345fghij";
    string s2 = "abxyz123fguvij";


    cout << "The longest common subsequence is : " << findLCS(s1, s2) << endl;
    return 0;
}

//totally fucked up today, didn't solve any new problem, like totally fucked up, yeah that's true
//did nothing today also