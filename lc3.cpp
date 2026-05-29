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

    int lengthOfSubstring(string s) {
        int n = s.size(), l = 0, r = 0, maxLen = 0;
        int hash[26];
        fill(hash, hash+26, -1);

        while(r < n) {
            if(hash[s[r]-'a'] == -1) hash[s[r]-'a'] = 1;
            else {
                while(s[l]-'a' != s[r]-'a') {
                    hash[s[l]-'a'] = -1;
                    l++;
                }
                hash[s[l]-'a'] = -1;
                hash[s[r]-'a'] = 1;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }


int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    cout << lengthOfSubstring(s) << endl;
    return 0;
}