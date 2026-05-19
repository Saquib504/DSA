#include <iostream>
#include <vector>
using namespace std;


char nextGreatestLetter(vector<char>& letters, char target) {
    int n = letters.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (letters[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return letters[low % n];
}


int main() {
    vector<char> letters = {'x', 'x', 'y', 'y'};
    char target = 'z';
    cout << nextGreatestLetter(letters, target) << endl; // Output: 'c'
    return 0;
}