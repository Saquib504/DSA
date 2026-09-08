#include <iostream>
using namespace std;

int countCommasII(int n) {
    int start = 1000;
    int total = 0;

    while(start <= n) {
        total += (n-start+1);
        start *= 1000;
    }

    return total;
}

int main() {
    int n; cin >> n;
    cout << "Total count : " << countCommas(n) << endl;
    return 0;
}