#include <iostream>
using namespace std;

// this is a solution where we haven't taken 0's in out array.

// R E C U R S I O N + M E M O I Z A T I O N
// int f(int index, int target, vector<int>&arr, vector<vector<int>>&memo) {
//     if(target == 0) return 1;
//     if(index == 0) return (arr[index] == target);

//     if(memo[index][target] != -1) return memo[index][target];

//     int notPick = f(index-1, target, arr, memo);

//     int pick = 0;

//     if(arr[index] <= target) pick = f(index-1, target - arr[index], arr, memo);

//     return memo[index][target] = notPick + pick;
// }


// T A B U L A T I O N - M E T H O D
// int countSubsequence(vector<int>&arr, int D) {
//     int n = arr.size();

//     int totalSum = 0;
//     for(int i = 0; i < n ;i++) totalSum += arr[i];

//     int target = (totalSum - D)/2;

//     vector<vector<int>>memo(n, vector<int>(target+1, 0));

//     for(int i = 0; i < n; i++) memo[i][0] =1;

//     if(arr[0] <= target) memo[0][arr[0]] = 1;

//     for(int i = 1; i < n; i++) {
//         for(int j = 1; j <= target; j++) {
//             int notPick = memo[i-1][j];
//             int pick = 0;
//             if(arr[i] <= j) pick = memo[i-1][j-arr[i]];


//             memo[i][j] = notPick+pick;
//         }
//     }
//     return memo[n-1][target];
// }


// S P A C E - O P T I M I Z A T I O N
int countSubsequence(vector<int>&arr, int D) {
    int n = arr.size();
    int totalSum = 0;
    for(int i = 0; i < n ;i++) totalSum += arr[i];
    int target = (totalSum - D)/2;

    vector<int>prev(target+1, 0);
    prev[0] = 1;

    if(arr[0] <= target) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++) {
        vector<int>temp(target+1, 0);
        temp[0] = 1;


        for(int j = 1; j <= target; j++) {
            int notPick = prev[j];

            int pick = 0;

            if(arr[i] <= j)
                pick = prev[j-arr[i]];

            temp[j] = notPick+pick;
        }
        prev = temp;
    }
    return prev[target];
}

int main() {

    vector<int> arr = {1,1,1,1,1};
    int D = 3;

    cout << "The no. of partitions with difference " << D << " is : " << countSubsequence(arr, D) << endl;
    return 0;
}