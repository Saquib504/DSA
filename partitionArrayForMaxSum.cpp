#include <iostream>
using namespace std;


// RECUSRION + MEMOIZATION
int f(int i, int k, vector<int>&arr, vector<int>&memo) {
    int n = arr.size();
    if(i == n) return 0;

    if(memo[i] != -1) return memo[i];

    int maxSum = INT_MIN, len = 0, maxELE = INT_MIN;

    for(int j = i; j < min(i+k, n); j++) {
        len++;
        maxELE = max(maxELE, arr[j]);
        int sum = len*maxELE + f(j+1, k, arr, memo);
        maxSum = max(maxSum,sum);
    }

    return memo[i] = maxSum;
}

// TABULATION METHOD
int maxSum(vector<int>&arr, int k) {
    int n = arr.size();

    vector<int>memo(n, 0);

    for(int i = n-1; i >= 0; i--) {
        int maxELE = INT_MIN, len = 0;
        int sum = INT_MIN;
        for(int j = i; j < min(n, i+k); j++) {
            len++;
            maxELE = max(maxELE, arr[j]);
            sum = max(sum, len*maxELE + memo[j+1]);
        }
        memo[i] = sum;
    }

    return memo[0];
}

int main() {

    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    cout << "The max sum we can get by partitioning array into k length subsets is " << maxSum(arr, k) << endl;

    return 0;
}