#include <iostream>
#include <vector>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int j, vector<int>&cuts, vector<vector<int>>&memo) {
//     if(i > j) return 0;

//     if(memo[i][j] != -1) return memo[i][j];

//     int cost = 1e9;

//     for(int ind = i; ind <=j; ind++) {
//         cost = min(cost, cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts, memo) + f(ind+1, j, cuts, memo));
//     }

//     return memo[i][j] = cost;
// }


//TABULATION METHOD
int minCutCost(int n, int c, vector<int>&cuts) {
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>>memo(c+2, vector<int>(c+2, 0));

    for(int i = c; i >=1; i--) {
        for(int j = 1; j <= c; j++) {
            if(i > j) continue;
            int cost = INT_MAX;
            for(int ind = i; ind <= j; ind++) {
                cost = min(cost, cuts[j+1] - cuts[i-1] + memo[i][ind-1] + memo[ind+1][j]);
            }
            memo[i][j] = cost;
        }
    }

    return memo[1][c];
}

int main() {
    vector<int>cuts = {1,3,4,5};
    int c = cuts.size();
    int n = 7;
    cout << "The minimum cost to cut a stick is : " << minCutCost(n, c, cuts) << endl;
    return 0;

}