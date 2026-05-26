#include <iostream>
#include <unordered_set>
using namespace std;

int numSpecialChars(string s) {
    int count = 0;
    unordered_set<char> seen(s.begin(), s.end());

    for(char c = 'a'; c <= 'z'; c++) {
        if(seen.count(c) && seen.count(c-32)) {
            count++;
        }
    }
    return count;
}


int main() {
    cout << endl;
    cout << "LC3120: Count Special Characters in a String" << endl;
    string s; cout << "Enter the string: ";
    cin >> s;

    cout << "Number of special characters in the string: " << numSpecialChars(s) << endl;
    return 0;
}