#include <iostream>
using namespace std;


int smallestRepunitDivByK(int k) {
    if(k % 2 == 0 || k % 5 == 0)return -1;
    int remainder = 1 % k;
    int cnt = 1;
    
    while(remainder != 0) {
        remainder = (remainder*10 + 1) % k;
        cnt++;
    }

    return cnt;
}


int main() {
    int k = 2;
    int result = smallestRepunitDivByK(k);
    cout << "The smallest integer consisting of only '1's that is divisible by k is : " << result << endl;
    return 0;
}