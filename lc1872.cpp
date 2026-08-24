#include <iostream>
using namespace std;

int stoneGameVIII(vector<int>& stones) {
    int n = stones.size();

    for(intt i = 1; i < n; i++) {
        stones[i] = stones[i-1] + stones[i];
    }

    //taking the optimal base case -> Alice takes all the stones at once
    int maxDiff = stones[n-1];

    for(int i = n-2; i >= 1; i--) {
        //already taken left half, Bob is left with the rest
        int leftSum = stones[i] - maxDiff;
        maxDiff = max(maxDiff, leftSum);
    }

    return maxDiff;
}

int main() {
    vector<int> stones;
    cout << "Enter the stones present: ";
    while(true) {
        int n; cin >> n; 
        if(n == -1) break;
        stones.push_back(n);
    }

    cout << "Maximum Difference : " << stoneGameVIII(stoneGameVIII) << endl;
    return 0;
}