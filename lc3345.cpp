#include <iostream>
 using namespace std;

 int digitProd(int n) {
    int prod = 1;

    while(n) {
        int digit = n % 10;
        prod *= digit;

        n /= 10;
    }

    return prod;
 }

 int smallestNumber(int n, int t) {
    while(n <= 100) {
        int prod = digitProd(n);
        if(prod % t == 0)return n;
        else n++;
    }
    return -1;
 }

 int main() {
    int n, t; cout << "Enter the number and the divisor t: "; cin >> n >> t;

    cout << "The smallest divisible digit product is : " << smallestNumber(n, t) << endl;

    return 0;
 }