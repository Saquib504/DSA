#include <iostream>
using namespace std;


    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;

        int hash[256];
        fill(hash, hash + 256, -1);

        while(r < n) {
            if(hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }


int main() {
    string s = "au";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}