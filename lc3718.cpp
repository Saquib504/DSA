#include <iostream>
using namespace std;


int missingMultiple(vector<int>& nums, int k) {
    bitset<101> bitPresent;
    for(int num : nums) {
        bitPresent.set(num);
    }
    int multiple = k;
    while(multiple < 100 && bitPresent.test(multiple)) {
        multiple += k;
    }
    return multiple;
}

int main() {
    int k; cout << "Enter the value of divisor k : "; cin >> k;
    vector<int> nums;
    cout << "Enter the elements of nums: ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums.push_back(n);
    }

    cout << "Smallest missing multiple is " << missingMultiple(nums, k) << endl;
    return 0;
}