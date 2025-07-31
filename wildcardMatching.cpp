#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// bool f(int i, int j, string&s1, string&s2, vector<vector<int>>&memo) {
//     if(i == 0 && j == 0) return true;
//     if(i == 0 && j > 0) return false;

//     if(j == 0 && i > 0) {
//         while(i > 0) {
//             if(s1[i] != '*') return false;
//         }
//         return true;
//     }

//     if(memo[i][j] != -1) return memo[i][j];

//     if(s1[i] == s2[j] || s1[i] == '?'){
//         return memo[i][j] = f(i-1, j-1,  s1,s2,memo);
//     }

//     if(s1[i] == '*') {
//         return memo[i][j] = f(i-1, j, s1,s2,memo) || f(i,j-1,s1,s2,memo);
//     }

//     return memo[i][j] = false;
// }


// TABULATION METHOD
// bool wildcard(string&s1, string &s2) {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<bool>>memo(n+1,vector<bool>(m+1,false));
//     memo[0][0] = true;
//     for(int j = 1; j <= m; j++) {
//         memo[0][j] = false;
//     }

//     for(int i = 1; i <= n; i++) {
//         int flag = true;
//         for(int ii = 1; ii <= i; ii++) {
//             if(s1[ii] != '*') {
//                 flag = false;
//                 break;
//             }
//         }
//         memo[i][0] = flag;
//     }

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             if(s1[i-1] == s2[j-1] || s1[i-1] == '?') {
//                 memo[i][j] = memo[i-1][j-1];
//             }
//             else if(s1[i-1] == '*') {
//                 memo[i][j] = memo[i-1][j] || memo[i][j-1];
//             }
//             else memo[i][j] = false;
//         }
//     }
//     return memo[n][m];
// }

// SPACE OPTIMIZATION
bool wildcard(string&s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0);
    prev[0] = true;
    for(int j = 1; j <= m; j++) {
        prev[j] = false;
    }


    for(int i = 1; i <= n; i++) {
        vector<int>temp(m+1, 0);int flag = true;
        for(int ii = 1; ii <= i; ii++) {
            if(s1[ii] != '*') {
                flag = false;
                break;
            }
        }
        temp[0] = flag;
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?') {
                temp[j] = prev[j-1];
            }
            else if(s1[i-1] == '*') {
                temp[j] = prev[j] || temp[j-1];
            }
            else temp[j] = false;
        }
        prev = temp;
    }
    return prev[m];
}



int main() {
    string s1; cout << "Enter string 1 : "; cin >> s1;
    string s2; cout << "Enter string 2 : "; cin >> s2;

    if(wildcard(s1,s2)) {
        cout << "\nYes, the strings match\n";
    } else {
        cout << "\nNo, the strings does not match\n";
    }

    return 0;
}