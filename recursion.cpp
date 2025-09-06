#include <iostream>
using namespace std;

void swapArray(int i, int n, vector<int>&arr) {
    if(i >= n/2) return;

    int swap = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = swap;

    return swapArray(i+1,n, arr);
}

bool isPalindrome(int i, int n, string&s) {
    
    if(i > n/2) return true;

    return (s[i] == s[n-i-1]) & isPalindrome(i+1,n,s);
}

int fibonacci(int n) {
    if(n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {

    int n; cin >> n;

    cout << fibonacci(n) << endl;
    return 0;
}