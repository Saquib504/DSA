#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


int kDistinctChar(string& s, int k) {
    //your code goes here
    int n = s.size();
    int l = 0, r = 0, maxLen = 0;
    unordered_map<char, int> mpp;

    while(r < n) {
        mpp[s[r]]++;
        while(mpp.size() > k) {
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }

        // current window [l..r] has at most k distinct chars
        if(mpp.size() <= (size_t)k) {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
    }

    return maxLen;
}



int main() {
    string s; int k;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << kDistinctChar(s, k) << endl;
    return 0;
}