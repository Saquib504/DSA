#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int numberOfSpecialChars(string word) {
    int n = word.size();

    int lastLower[26], firstUpper[26];
    fill(lastLower, lastLower+26, -1);
    fill(firstUpper, firstUpper+26, -1);

    for(int i = 0; i < n; i++) {

        if(word[i] >= 'a' && word[i] <= 'z') {
            lastLower[word[i] - 'a'] = i;
        }
        else {
            if(firstUpper[word[i] - 'A'] == -1) {
                firstUpper[word[i] - 'A'] = i;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << endl;
    cout << "LC3121: Count Special Characters in a String II" << endl;
    string s; cout << "Enter the string: ";
    cin >> s;

    cout << "Number of special characters in the string: " << numberOfSpecialChars(s) << endl;
    return 0;
}