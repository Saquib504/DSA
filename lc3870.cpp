#include <iostream>
using namespace std;

int countCommas(int n) {
    if(n < 1000) return 0;
    return n - 1000 + 1;
}

int main() {
    int n; cin >> n;
    cout << "Total count : " << countCommas(n) << endl;
    return 0;
}