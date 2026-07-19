#include <iostream>
using namespace std;


string removeDuplicateLetters(string s) {
    int freq[27] = {0};
    bitset<27> seen;
    string stk;

    for(auto& c : s) {
        freq[c&31]++;
    }

    for(auto& c : s) {
        int x = c&31;
        freq[x]--;

        if(seen.test(x))continue;

        while(stk.length() && stk.back() > c && freq[stk.back()&31]) {
            seen.reset(stk.back()&31);
            stk.pop_back();
        }

        stk.push_back(c);
        seen.set(x);
    }
    return stk;
}

int main() {
    string s; cout << "Enter the string : "; cin >> s;
    cout << "The final string after removing duplicates: " << removeDuplicateLetters(s) << endl;

    return 0;
}