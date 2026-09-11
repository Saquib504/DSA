#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int countUniqueEvenNumbers(const vector<int>& digits) {
    // Step 1: Calculate frequency of each digit
    vector<int> freq(10, 0);
    for (int d : digits) {
        freq[d]++;
    }

    int totalUniqueEven = 0;

    // Step 2: Sum over all valid distinct LSB choices
    for (int e = 0; e <= 8; e += 2) {
        if (freq[e] == 0) continue; // Must have at least 1 copy of e
        freq[e]--; // Temporarily consume 1 copy for LSB

        // Step 3: Sum over all valid distinct MSB choices (1 through 9)
        for (int m = 1; m <= 9; m++) {
            if (freq[m] == 0) continue; // Must have at least 1 copy left for MSB
            freq[m]--; // Temporarily consume 1 copy for MSB

            // Step 4: Count all distinct digits available for Mid Bit
            for (int d = 0; d <= 9; d++) {
                if (freq[d] > 0) {
                    totalUniqueEven++; // Valid 3-digit tuple (m, d, e)
                }
            }

            freq[m]++; // Restore MSB
        }

        freq[e]++; // Restore LSB
    }

    return totalUniqueEven;
}


int main() {
    vector<int> nums;
    cout << "Enter nums: ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        nums.push_back(n);
    }

    cout << "Unique 3-Digit Even Numbers : " << countUniqueEvenNumbers(nums) << endl;

    return 0;
}