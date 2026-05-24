#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s1, string s2) {
    int n = (int)s1.size();
    int m = (int)s2.size();

    vector<int> start(m, -1);
    int bestLen = INT_MAX;
    int bestStart = -1;

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] != s2[j]) continue;

            if (j == 0) {
                start[0] = i;
            } else if (start[j - 1] != -1) {
                start[j] = start[j - 1];
            }
        }

        if (start[m - 1] != -1) {
            int currStart = start[m - 1];
            int currLen = i - currStart + 1;

            if (currLen < bestLen || (currLen == bestLen && currStart < bestStart)) {
                bestLen = currLen;
                bestStart = currStart;
            }
        }
    }

    return bestStart == -1 ? "" : s1.substr(bestStart, bestLen);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << minWindow(s1, s2) << '\n';
    return 0;
}