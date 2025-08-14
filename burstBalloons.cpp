#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int j, vector<int>&balloons, vector<vector<int>>&memo) {
//     if(i > j) return 0;

//     if(memo[i][j] != -1) return memo[i][j];

//     int cost = INT_MIN;

//     for(int ind = i; ind <= j; ind++) {
//         cost = max(cost, balloons[i-1]*balloons[ind]*balloons[j+1] + f(i, ind-1, balloons, memo) + f(ind+1, j, balloons, memo));
//     }
//     return memo[i][j] = cost;
//}

// TABULATION METHOD
int burstBalloons(vector<int>&balloons) {
    int n = balloons.size();
    balloons.insert(balloons.begin(), 1);
    balloons.push_back(1);

    vector<vector<int>>memo(n+2, vector<int>(n+2,0));

    for(int i = n; i >= 1; i--) {
        for(int j = i; j <= n; j++) {
            int cost = INT_MIN;
            for(int ind = i; ind <= j; ind++) {
                cost = max(cost, balloons[i-1]*balloons[ind]*balloons[j+1] + memo[i][ind-1] + memo[ind+1][j]);
            }
            memo[i][j] = cost;
        }
    }

    return memo[1][n];
}

int main() {
    vector<int> balloons = {3,1,5,8};

    cout << "The max value after bursting balloons is " << burstBalloons(balloons) << endl;
    return 0;
}