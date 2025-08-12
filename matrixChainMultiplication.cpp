#include <iostream>
using namespace std;

// RECURSION + MEMOIZATION
// int f(int i, int j, vector<int>&arr, vector<vector<int>>&memo) {
//     if(i == j) return 0;

//     if(memo[i][j] != -1) return memo[i][j];

//     int steps = 1e9;

//     for(int k = i; k < j; k++) {
//         steps = min(steps, arr[i-1]*arr[k]*arr[j] + f(i, k, arr, memo) + f(k+1, j, arr, memo));
//     }

//     return memo[i][j] = steps;
// }



// TABULATION METHOD
int MCM(vector<int>&arr, int N) {
    vector<vector<int>>memo(N, vector<int>(N, 0));

    for(int i = 1; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int steps = 1e9;

            for(int k = i; k < j; k++) {
                steps = min(steps, arr[i-1]*arr[k]*arr[j] + memo[i][k] + memo[k+1][j]);
            }

            memo[i][j] = steps;
        }
    }

    return memo[1][N-1];
}


int main() {

    vector<int>arr = {10,30,5,60};
    int N = arr.size();

    cout << "The minimum operations required for matrix multiplication is : " << MCM(arr, N) << endl;
    return 0;
}