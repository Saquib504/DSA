#include <iostream>
using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return 1;
    else if(n == 2) return 2;
    else {
        int msb = bit_width(static_cast<unsigned int>(n));
        return 1 << msb;
    }
}


int main() {
vector<int> nums;

cout << "\nEnter the elements in the nums array : ";
while(true) {
    int n; 
    cin >> n;
    if(n == -1)break;
    else {
        nums.push_back(n);
    }
}

cout << "\nMax unique XOR triplets : " << uniqueXorTriplets(nums) << endl;
return 0;
}