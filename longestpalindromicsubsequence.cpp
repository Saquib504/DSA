#include <iostream>
#include <string>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int j, string&s1, string &s2, vector<vector<int>>&memo) {
//     if(i < 0 || j < 0) return 0;
//     if(s1[i] == s2[j]) {
//         return 1 + f(i-1, j-1, s1, s2, memo);
//     }

//     if(memo[i][j] != -1) return memo[i][j];

//     return memo[i][j] = max(f(i-1, j, s1, s2, memo), f(i, j-1, s1, s2, memo));
// }


// TABULATION METHOD
// int longestPalindrome(string& s1, string&s2) {
//     int n = s1.size();

//     vector<vector<int>>memo(n+1, vector<int>(n+1,0));

//     for(int i = 1; i <=n; i++) {
//         for(int j = 1; j <= n; j++) {

//             if(s1[i-1] == s2[j-1]) {
//                 memo[i][j] = 1 + memo[i-1][j-1];
//             }
//             else {
//                 memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
//             }
//         }
//     }
//     return memo[n][n];
    
// }

// SPACE OPTIMIZATION
int longestPalindrome(string& s1) {
    int n = s1.size();

    vector<int>prev(n+1, 0);

    for(int i = 1; i <=n; i++) {
        vector<int>temp(n+1, 0);
        for(int j = 1; j <= n; j++) {

            if(s1[i-1] == s1[n-j]) {
                temp[j] = 1 + prev[j-1];
            }
            else {
                temp[j] = max(prev[j], temp[j-1]);
            }
        }
        prev = temp;
    }
    return prev[n];
    
}


int main() {
    string str1; cout << "Enter : ";cin >> str1;
    int n = str1.length();
    // string str2;

    // for(int i = n-1; i >= 0; i--) {
    //     str2 += str1[i];
    // }

    cout << "The longest palindromic subsequence is " << longestPalindrome(str1) << endl;
    return 0;
}