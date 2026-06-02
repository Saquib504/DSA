#include <iostream>
#include <vector>
using namespace std;

//TC -> O(logN), SC -> O(1)
int digitFrequencyScore(int n) {
    int freq[10];
    fill(freq, freq+10, 0);
    int sum = 0;

    while(n > 0) {
        int temp = n%10;
        freq[temp]++;
        n /= 10;
    }

    for(int i = 0; i < 10; i++) {
        sum += i * freq[i];
    }

    return sum;
}


int main() {
    int n ;
    cin >> n;
    cout << digitFrequencyScore(n) << endl;
    return 0;
}