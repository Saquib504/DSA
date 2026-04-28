#include <iostream>
using namespace std;

/*
3889. Mirror Frequency Distance
Solved
Medium
premium lock icon
Companies

Hint
You are given a string s consisting of lowercase English letters and digits.

For each character, its mirror character is defined by reversing the order of its character set:

For letters, the mirror of a character is the letter at the same position from the end of the alphabet.
For example, the mirror of 'a' is 'z', and the mirror of 'b' is 'y', and so on.
For digits, the mirror of a character is the digit at the same position from the end of the range '0' to '9'.
For example, the mirror of '0' is '9', and the mirror of '1' is '8', and so on.
For each unique character c in the string:

Let m be its mirror character.
Let freq(x) denote the number of times character x appears in the string.
Compute the absolute difference between their frequencies, defined as: |freq(c) - freq(m)|
The mirror pairs (c, m) and (m, c) are the same and must be counted only once.

Return an integer denoting the total sum of these values over all such distinct mirror pairs.

*/

int mirrorFrequnecy(string s) {  // ← check this name matches the template!
    int freq[128] = {};
    for (unsigned char c : s) freq[c]++;
    
    int ans = 0;
    
    for (char c = 'a'; c <= 'm'; c++) {
        char m = 'a' + 'z' - c;
        ans += abs(freq[(int) c] - freq[(int)m]);
    }
    
    for (char c = '0'; c <= '4'; c++) {
        char m = '0' + '9' - c;
        ans += abs(freq[(int)c] - freq[(int)m]);
    }
    
    return ans;
}

/*
3890. Integers With Multiple Sum of Two Cubes
Solved
Medium
premium lock icon
Companies

Hint
You are given an integer n.

An integer x is considered good if there exist at least two distinct pairs (a, b) such that:

a and b are positive integers.
a <= b
x = a3 + b3
Return an array containing all good integers less than or equal to n, sorted in ascending order.


*/


vector<int> findGoodIntegers(int n) {
    unordered_map<int , int> cnt;


    for(int a = 1; (long long)a*a*a <= n; a++) {
        for(int b = a; (long long)a*a*a + (long long)b*b*b <= n; b++) {
            cnt[a*a*a + b*b*b]++;
        }
    }

    vector<int> ans;
    for(auto c : cnt) {
        if(c.second >= 2)ans.push_back(c.first);
    }

    sort(ans.begin(), ans.end());

    return ans;
}




/*
3891. Minimum Increase to Maximize Special Indices
Solved
Medium
premium lock icon
Companies

Hint
You are given an integer array nums of length n.

An index i (0 < i < n - 1) is special if nums[i] > nums[i - 1] and nums[i] > nums[i + 1].

You may perform operations where you choose any index i and increase nums[i] by 1.

Your goal is to:

Maximize the number of special indices.
Minimize the total number of operations required to achieve that maximum.
Return an integer denoting the minimum total number of operations required.

 
*/


long long minIncrease(vector<int>& nums) {
    int n = nums.size();
    const long long INF = 1e18;

    vector<array<long long, 3>> dp(2);
    dp[0] = {0, 0, nums[0]};
    dp[1] = {-1, INF, 0};

    for(int i = 1; i < n; i++) {
        vector<array<long long, 3>> ndp(2);
        ndp[0] = ndp[1] = {-1, INF, 0};
        for(int ls = 0; ls <= 1; ls++) {
            if(dp[ls][1] == INF)continue;
            long long cnt = dp[ls][0], cost = dp[ls][1], eff_prev = dp[ls][2];


            if(make_pair(-cnt, cost) < make_pair(-ndp[0][0], ndp[0][1])) {
                ndp[0] = {cnt, cost, nums[i]};
            }

            if(i < n-1 && ls == 0) {

                long long need = max(eff_prev, (long long)nums[i+1]) + 1;
                long long extra = max(0LL, need - nums[i]);
                long long new_eff = max((long long)nums[i], need);
                long long new_cnt = cnt + 1, new_cost = cost + extra;
                if(make_pair(-new_cnt, new_cost) < make_pair(-ndp[1][0], ndp[1][1])) {
                    ndp[1] = {new_cnt, new_cost, new_eff};
                }
            }
        }
        dp = ndp;
    }
    long long ans = INF;
    for(int ls = 0; ls <= 1; ls ++) {
        if(dp[ls][1] < INF) ans = min(ans, dp[ls][1]);
    }
    return ans;
}



int main() {
    string s = "ab1z9";
    cout << mirrorFrequnecy(s) << endl;
    int n = 100;
    vector<int> goodIntegers = findGoodIntegers(n);
    cout << "Good integers less than or equal to " << n << ": ";
    for (int x : goodIntegers) {
        cout << x << " ";   
    }
    cout << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Minimum increase to maximize special indices: " << minIncrease(nums) << endl;
    return 0;
}