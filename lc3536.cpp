#include <iostream>
using namespace std;

int maxProduct(int n) {
    int max1 = 0, max2 = 0;

    while(n) {
        int digit = n % 10;
        n /= 10;
        if(digit > max1) {
            max2 = max1;
            max1 = digit;
        } else if(digit > max2) {
            max2 = digit;
        }
    }

    return max1 * max2;
}


int main() {
    int n; cout << "Enter the value of n: "; cin >> n;

    cout << "The maxPrduct of two largest digits in the n : " << maxProduct(n) << endl;

    return 0;
}