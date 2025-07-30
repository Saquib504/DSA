#include <iostream>
using namespace std;

// RECURSINO + MEMOIZATION
// TC -> O(NxM)
// SC -> (NxM) + O(N+M)
// int f(int i, int j, string &s1, string &s2, vector<vector<int>>&memo) {
//     if(i < 0) return j+1;
//     if(j < 0) return i+1;

//     if(memo[i][j] != -1) return memo[i][j];

//     if(s1[i] == s2[j]) {
//         return 0 + f(i-1, j-1,s1,s2,memo);
//     }

//     return memo[i][j] = min(1 + f(i-1,j,s1,s2,memo), min(1+f(i,j-1,s1,s2,memo), 1+f(i-1,j-1,s1,s2,memo)));
// }

// TABULATION METHOD
// TC -> O(NxM)
// SC -> (NxM)
// int editDistance(string&s1, string&s2) {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>>memo(n+1, vector<int>(m+1, 0));

//     for(int i = 0; i <= n; i++) {
//         memo[i][0] = i; 
//     }

//     for(int j = 1; j <= m; j++) {
//         memo[0][j] = j;
//     }

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             if(s1[i-1] == s2[j-1]) {
//                 memo[i][j] = 0 + memo[i-1][j-1];
//             }
//             else {
//                 memo[i][j] = min(1+memo[i-1][j], min(1+memo[i][j-1], 1+memo[i-1][j-1]));
//             }
//         }
//     }
//     return memo[n][m];
// }


// SPACE OPTIMIZATION
// TC -> O(NxM)
// SC -> (M)
int editDistance(string&s1, string&s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1,0);
    for(int j = 1; j <= m; j++) {
        prev[j] = j;    //Base case-1
    }

    for(int i = 1; i <= n; i++) {
        vector<int>temp(m+1, 0);
        temp[0] = i;    //Base case-2
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                temp[j] = 0 + prev[j-1];
            }
            else {
                temp[j] = min(1+prev[j], min(1+temp[j-1], 1+prev[j-1]));
            }
        }
        prev = temp;
    }
    return prev[m];
}

int main() {
    string s1; cout << "Enter string 1 = "; cin >> s1;
    string s2; cout << "Enter string 1 = "; cin >> s2;

    cout << "The minimum operatinos to convert string S1 into S2 is " << editDistance(s1,s2) << endl;
    return 0;
}