#include <iostream>
using namespace std;

bool checkDivisibility(int n) {
    int sum = 0, product = 1, temp = n;

    while(temp > 0) {
        sum += temp%10;
        product *= temp%10;

        temp /= 10;
    }

    return n %(sum +  product) == 0;
}

int main() {
    int n; cout << "Enter n: "; cin >> n;

    if(checkDivisibility(n)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}