#include <iostream>
using namespace std;

bool isPalindrome(int i, int j, string&s) {
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// RECURSION + MEMOIZATION
// int f(int i, int n, string&s, vector<int>&memo) {
//     if(i == n) return 0;

//     if(memo[i] != -1) return memo[i];
//     int minCost = INT_MAX;

//     for(int j = i; j < n; j++) {
//         if(isPalindrome(i,j,s)) {
//             minCost = min(minCost, 1 + f(j+1,n,s,memo));
//         }
//     }

//     return memo[i] = minCost;
// }


// TABULATION METHOD
int minPartition(string&s) {
    int n = s.length();

    vector<int>memo(n+1,0);
    memo[n] = 0;
    

    for(int i = n-1; i >= 0; i--) {
        int cost = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, s)) {
                cost = min(cost, 1 + memo[j+1]);
            }
        }
        memo[i] = cost;
    }

    return memo[0] - 1;
}

int main() {

    string str = "bababcbadcede";

    cout << "The minimum number of partitions to make are " << minPartition(str) << endl;

    return 0;
}

//there is a solution to this problem that solve it in tiem complxity of O(NlogN)
