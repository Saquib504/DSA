#include <iostream>
using namespace std;

static int numOfStrings(vector<string>& patterns, string word) {
    string_view s(word);
    int cnt=0;
    for(string_view p: patterns){
        cnt+=s.find(p)!=-1;
    }
    return cnt;
}


//patterns = ["a","abc","bc","d"], word = "abc"

int main() {
    vector<string> patterns;
    cout << "Enter the patterns: ";
    while(true) {
        string s; cin >> s;
        if(s == "NULL")break;
        patterns.push_back(s);
    }

    string word = "";
    cout << "\nEnter the word: "; cin >> word;

    cout << "Number of substrings : " << numOfStrings(patterns, word) << endl;

    return 0;
}