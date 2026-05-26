#include <iostream>
#include <unordered_set>
using namespace std;


string greatestLetter(string s) {
        unordered_set<char> st;

    for(char ch : s)
    {
        st.insert(ch);
    }

    for(char ch = 'Z'; ch >= 'A'; ch--)
    {
        if(st.find(ch) != st.end() &&
            st.find(ch + 32) != st.end())
        {
            return string(1, ch);
        }
    }

    return "";
}



int main() {
    cout << endl;
    cout << "LC2309: Greatest English Letter in Upper and Lower Case" << endl;
    string s; cout << "Enter the string: ";
    cin >> s;

    cout << "Greatest English letter in upper and lower case: " << greatestLetter(s) << endl;
    return 0;
}