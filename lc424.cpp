#include <iostream>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size(), l = 0, maxLen = 0;
    int hash[26] = {0};
    int maxFreq = 0;
    for(int r = 0; r < n; r++) {
        maxFreq = max(maxFreq, ++hash[s[r]-'A']);

        if(r-l+1 - maxFreq > k) {
            hash[s[l]-'A']--;
            l++;
        }

        maxLen = max(maxLen, r-l+1);
    }
    return maxLen;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << "Maximum length of substring with same characters after replacing at most " << k << " characters: " << characterReplacement(s, k) << endl;
    return 0;
}