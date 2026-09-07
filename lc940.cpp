#include <iostream>
using namespace std;


// Better Approach----------RECURSION + MEMOIZATION
// TC -> O(N)
// SC -> O(26)
int M = 1e9+7;
vector<int> prevIDX;
int dp[2001];
int solve(int n) {
    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    int total = (2*solve(n-1))%M;

    if(prevIDX[n] != 0){
        int duplicates = solve(prevIDX[n] - 1);
        total = (total - duplicates + M)%M;
    }

    return dp[n] = total;
}

int distinctSubseqIIRM(string s) {
    int n = s.length();
    prevIDX.assign(n+1, 0);
    memset(dp, -1, sizeof(dp));
    vector<int> lastScene(n+1, 0);

    for(int i = 1; i <= n; i++) {
        int c = s[i-1] - 'a';
        prevIDX[i] = lastScene[c];
        lastScene[c] = i;
    }

    return (solve(n) - 1 + M)%M;
}


int distinctSubseqIIBU(string s) {
    int n = s.length();
    prevIDX.assign(n+1, 0);
    memset(dp, -1, sizeof(dp));
    vector<int> lastScene(n+1, 0);

    for(int i = 1; i <= n; i++) {
        int c = s[i-1] -'a';
        prevIDX[i] = lastScene[c];
        lastScene[c] = i;
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        int total = (2*dp[i-1])%M;

        if(prevIDX[i] != 0) {
            int duplicates = dp[prevIDX[i] - 1];
            total = (total - duplicates + M) % M;
        }

        dp[i] = total;
    }

    return (dp[n] - 1 + M)%M;
}




int main() {
    string s;
    cout << "Enter string: "; cin >> s;

    cout << "Total number of distinct subsequences are : " << distinctSubseqIIBU(s) << endl;

    return 0;
}