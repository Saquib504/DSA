#include <iostream>
#include <vector>
using namespace std;


// int jumps(int i, int d, vector<int>& arr, int memo[]) {
//     int n = arr.size();
//     int res = 1;

//     if(memo[i] != 0) return memo[i];

//     //Jump left
//     for(int j = i-1; j >= max(0, i-d); j--) {
//         if(arr[j] > arr[i])break;
//         res = max(res, 1 + jumps(j, d, arr, memo));
//     }

//     //Jump right
//     for(int j = i+1; j <= min(n-1, i+d); j++) {
//         if(arr[j] > arr[i])break;
//         res = max(res, 1 + jumps(j, d, arr, memo));
//     }
//     return memo[i] = res;
// }

// int maxJumps(vector<int>& arr, int d) {
//     int n = arr.size();
//     int ans = 0;
//     int memo[n];
//     memset(memo, 0, sizeof(memo));
//     for(int i = 0; i < n; i++) {
//         ans = max(ans, jumps(i, d, arr, memo));
//     }
//     return ans;
// }


int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();
    int res = 1;

    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++) {
        vec.push_back({arr[i], i});
    }
    sort(begin(vec), end(vec));

    vector<int> memo(n, 1);

    for(auto it : vec) {
        int num = it.first;
        int i = it.second;
        int res = 1;

        //Left jump
        for(int j = i-1; j >= max(0, i-d); j++) {
            if(arr[j] >= arr[i])
                break;
            res = max(res, 1 + memo[j]);
        }

        for(int j = i+1; j <= min(n-1, i+d); j++) {
            if(arr[j] >= arr[i])
                break;
            res = max(res, 1 + memo[j]);
        }

        memo[i] = max(memo[i], res);
    }

    return *max_element(begin(memo), end(memo));
}



int main() {
    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};
    int d = 2;
    cout << maxJumps(arr, d) << endl;
    return 0;
}