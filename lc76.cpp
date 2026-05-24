#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;


string minWindow(string s, string t) {
    int n = s.size(), m = t.size(), l = 0, r = 0, minLen = INT_MAX, sIDX = -1, cnt = 0;
    int hash[256] = {0};
    for(char c : t)hash[c]++;

    while(r < n) {
        if(hash[s[r]] > 0) cnt++;
        hash[s[r]]--;

        while(cnt == m) {
            if(r-l+1 < minLen) {
                minLen = r-l+1;
                sIDX = l;
            }
            hash[s[l]]++;
            if(hash[s[l]] > 0) cnt--;

            l++;
        }
        r++;
    }
    return sIDX == -1 ? "" : s.substr(sIDX, minLen);

}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    cout << minWindow(s, t) << endl;
    return 0;
}