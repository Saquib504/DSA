#include <iostream>
using namespace std;

string smallestPalindrome(string s) {
    int n = s.size(), j = 0;
    int freq[26]{};

    for(int i = 0; i < n >> 1; i++) {
        freq[(s[i] & 31) - 1]++;
    }

    for(int i = 0; i < 26; i++) {
        while(freq[i]--) {
            s[j] = 'a' + i;
            s[n-1-j++] = 'a' + i;
        }
    }

    return s;
}


int main() {
    string s; cout << "Enter the palindrome string: "; cin >> s;

    cout << "The smallest palindromic rearrangement is : " << smallestPalindrome(s) << endl;

    return 0;
}