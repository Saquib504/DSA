/*

583. Delete Operation for Two Strings
Solved      --------        Medium
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:
1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

*/







#include <iostream>
using namespace std;


int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<int>prev(m+1, 0);

    for(int i =1; i <= n; i++) {
        vector<int>temp(m+1, 0);

        for(int j = 1; j <= m; j++) {
            if(word1[i-1] == word2[j-1]) {
                temp[j] = 1 + prev[j-1];
            }
            else {
                temp[j] = max(prev[j], temp[j-1]);
            }
        }
        prev = temp;
    }
    cout << prev[m] << endl;
    return n + m - 2*prev[m];
}

int main() {
    string s1 = "";cout << "Enter s1 : "; cin >> s1;
    string s2 = "";cout << "Enter s2 : "; cin >> s1;
    cout << minDistance(s1,s2) << endl;
    cout << "The minimum number of deletions required to make two strings same is " << minDistance(s1, s2) << endl;
    return 0;
}
