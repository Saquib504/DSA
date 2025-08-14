#include <iostream>
using namespace std;

vector<long long> pf;
vector<vector<long long>> dp;

long long process(vector<int>& stones, int i, int j, int k) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    long long cost = LLONG_MAX;
    for (int mid = i; mid < j; mid += (k - 1)) {
        cost = min(cost, process(stones, i, mid, k) + process(stones, mid + 1, j, k));
    }

    if ((j - i) % (k - 1) == 0) {
        cost += pf[j + 1] - pf[i];
    }

    return dp[i][j] = cost;
}

int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    if ((n - 1) % (k - 1) != 0) return -1; 

    pf.push_back(0);
    for (auto e: stones) pf.push_back(e + pf.back());

    dp = vector<vector<long long>>(n+1, vector<long long>(n+1, -1));
    return process(stones, 0, n - 1, k);
}

int main() {

    vector<int>stones = {3,5,1,2,6};
    int k = 2;

    cout << "The minimum cost to merge all stones is " << mergeStones(stones, k) << endl;

    return 0;
}