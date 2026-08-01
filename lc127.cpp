#include <iostream>
#include <unordered_set>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    while(!q.empty()) {
    auto [word, steps] = q.front(); q.pop();

    if(word == endWord) return steps;

    for(int i = 0; i < word.size(); i++) {
        char originalChar = word[i];
        for(char ch = 'a'; ch <= 'z'; ch++) {
            word[i] = ch;
            if(st.find(word) != st.end()) {
                st.erase(word);
                q.push({word, steps+1});
            }
        }
        word[i] = originalChar;
    }
    }

    return 0;
}

int main() {
    string beginWord, endWord;
    vector<string> wordList;

    cout << "Enter the words present in the wordList: ";
    while(true) {
        string s;
        cin >> s;
        if(s == "exit" || s == "done" || s == "cancel")break;
        else wordList.push_back(s);
    }

    cout << "Enter the beginWord and the endWord : "; cin >> beginWord >> endWord;

    cout << "The number of steps taken to transform the sequence from beginWord to endWord: " << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}