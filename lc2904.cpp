#include <iostream>
#include <string>
using namespace std;

// Brute Force Approach --> Using nested for loops
// TC -> O(N^2)
// SC -> O(1)
string shortestBeautifulSubstringBF(string s, int k) {
    int n = s.length();
    string res = "";
    int prevLen = INT_MAX;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == '1') {
                cnt++;
            }
            if(cnt == k){ 
                if(j-i+1 < prevLen) {
                    prevLen = j-i+1;
                    res = s.substr(i, j-i+1);
                    break;
                }
            }
        }
    }

    return res;
}

// Better Approach  --> Using Queue
// TC -> O(N)
// SC -> O(N)
string shortestBeautifulSubstringBE(string s, int k) {
    int n = s.length();
    queue<char> q;
    int cnt = 0, idx = 0, prevLen = INT_MAX;
    string res = "";

    for (int i = 0; i < n; i++) {
        q.push(s[i]);
        if (s[i] == '1') {
            cnt++;
        }

        // 1. Shrink if count exceeds k
        while (cnt > k) {
            if (q.front() == '1') {
                cnt--;
            }
            idx++;
            q.pop();
        }

        // 2. Trim leading zeros when count reaches k
        while (cnt == k && !q.empty() && q.front() == '0') {
            idx++;
            q.pop();
        }

        // 3. Update result when valid window of size k ones is formed
        if (cnt == k) {
            int currentLen = q.size();
            string currentSub = s.substr(idx, currentLen);

            if (currentLen < prevLen) {
                prevLen = currentLen;
                res = currentSub;
            } else if (currentLen == prevLen) {
                // Lexicographical check for equal lengths
                if (currentSub < res) {
                    res = currentSub;
                }
            }
        }
    }

    return res;
}

// Optimal Approach --> Using Sliding Window
// TC -> O(N)
// SC -> O(1)
string shortestBeautifulSubstringOP(string s, int k) {
    int n = s.length();
    int cnt = 0, minLen = INT_MAX;
    int l = 0;
    string res = "";

    for (int r = 0; r < n; r++) {
        if (s[r] == '1') cnt++;

        // Shrink from left if count exceeds k OR if there are redundant leading zeros
        while (cnt > k || (l < r && s[l] == '0')) {
            if (s[l] == '1') cnt--;
            l++;
        }

        // Check if valid window with exactly k ones
        if (cnt == k) {
            int currentLen = r - l + 1;
            string currentSub = s.substr(l, currentLen);

            if (currentLen < minLen) {
                minLen = currentLen;
                res = currentSub;
            } else if (currentLen == minLen) {
                // Lexicographical comparison for equal lengths
                if (currentSub < res) {
                    res = currentSub;
                }
            }
        }
    }

    return res;
}


int main() {
    string s; cout << "Enter binary string: "; cin >> s;
    int k; cout << "Enter k: "; cin >> k;

    cout << "Shortest Beautiful Substring : " << shortestBeautifulSubstringBF(s, k) << endl;
    cout << "Shortest Beautiful Substring : " << shortestBeautifulSubstringBE(s, k) << endl;
    cout << "Shortest Beautiful Substring : " << shortestBeautifulSubstringOP(s, k) << endl;
    return 0;
}