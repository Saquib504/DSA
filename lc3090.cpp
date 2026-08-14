#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int maximumLengthSubstring(string s) {
    int n = s.size();
    unordered_map<int, int> count;
    int ans = 0;
    int l = 0;

    for(int r = 0; r < n; r++) {
        count[s[r]]++;

        while(count[s[r]] > 2) {
            count[s[l]]--;
            l++;
        }

        ans = max(ans, r-l+1);
    }

    return ans;
}

int main() {
    string s; cout << "Enter the string: "; cin >> s;

    cout << "The length of the longest substring with all characters having frequency 2 is " << maximumLengthSubstring(s) << endl;

    return 0;
}