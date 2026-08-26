#include <iostream>
using namespace std;

int climbStairs(int n) {
    if(n <= 0) return 0;
    else if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 3;
    
        int oneStep = 2;
        int twoStep = 1;

        for(int i = 2; i < n; i++) {
            int allWays = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = allWays;
        }

    return oneStep;
}

int main() {
    int n; cout << "Enter n : "; cin >> n;
    cout << "\n" << climbStairs(n) << endl;
    return 0;
}