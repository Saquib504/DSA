#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while(b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

long long gcdSum(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return 0;
    
    vector<int> prefixGCD(n);
    int mx = nums[0];

    prefixGCD[0] = gcd(nums[0], mx);

    for(int i = 1; i < n; i++) {
        mx = max(mx, nums[i]);
        prefixGCD[i] = gcd(nums[i], mx);
    }

    sort(prefixGCD.begin(), prefixGCD.end());

    long long sumGCD = 0;
    int l = 0, h = n-1;

    while(l < h) {
       sumGCD += gcd(prefixGCD[l], prefixGCD[h]);
       l++;
       h--;
    }

    return sumGCD;
}



int main() {
    int n; cout << "Enter the size of the nums array: "; cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        nums[i] = j;
    }

    cout << "The gcd Sum of all the elements is : " << gcdSum(nums) << endl;
    return 0;
}