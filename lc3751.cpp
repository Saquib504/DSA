#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TC -> O(MAX), SC -> O(MAX)
// solution link 
//https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/solutions/8311776/solution-by-la_castille-9dlq
static constexpr int MAX = 100001;
static inline int dp[MAX], pref[MAX];

static inline bool init = []() {
    for(int i = 100; i < MAX; i++) {
        int r = i % 10;
        int m = (i / 10) % 10;
        int l = (i / 100) % 10;

        bool isWave = (m > max(l, r)) | (m < min(l,r));
        dp[i] = dp[i / 10] + isWave;
        pref[i] = pref[i-1] + dp[i];
    }
    return 0;
}();

int totalWaviness(int num1, int num2) {
    return pref[num2] - pref[num1-1];
}

int main() {
    int num1, num2;
    cout << "Enter the range (num1 num2): ";
    std::cin >> num1 >> num2;
    std::cout << totalWaviness(num1, num2) << std::endl;
    return 0;
}