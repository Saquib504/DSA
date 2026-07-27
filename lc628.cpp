#include <iostream>
using namespace std;

int maximumProduct(vector<int>& A) {
    int a = -1001, b = a, c = b;    // max 3
    int x =  1001, y = x;           // min 2

    for (auto& n : A) {
        c = max(c, min(b, n));     // Shift to 3rd max
        b = max(b, min(a, n));     // Shift to 2nd max
        a = max(a, n);              // Update 1st max

        y = min(y, max(x, n));     // Shift to 2nd min
        x = min(x, n);              // Update 1st min
    }

    return max(a * b * c, a * x * y);
}

int main() {
    vector<int> nums;

    cout << "\nEnter the elements: ";
    while(true) {
        int n;
        cin >> n;
        if(n==-1)break;
        nums.push_back(n);
    }

    cout << "\nMaximum product of 3 numbers : " << maximumProduct(nums) << endl;
    return 0;
}