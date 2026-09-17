#include <iostream>
using namespace std;



int minSumOfLengths(vector<int>& A, int k) {
    int n = A.size();
    int res = n + 1, sum = 0, i = 0;

    vector<int> dp(n + 1, n);

    for (int j = 0; j < n; j++) {
        sum += A[j];

        while (sum > k)
            sum -= A[i++];

        dp[j + 1] = dp[j];

        if (sum == k) {
            res = min(res, j - i + 1 + dp[i]);
            dp[j + 1] = min(dp[j], j - i + 1);
        }
    }

    return res == n + 1 ? -1 : res;
}

int main() {
    vector<int> a;
    cout << "Enter Array: ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        a.push_back(n);
    }
    int target;
    cout << "Enter target: "; cin >> target;

    cout << "Sum of the length of both subarrays : " <<  minSumOfLengths(a, target) << endl;
    return 0;
}