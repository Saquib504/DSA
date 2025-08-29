#include <iostream>
using namespace std;

struct Node {
    Node*links[26];
    bool isEnd = false;
};

class Trie {
    Node*root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node*node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->links[word[i] - 'a']) {
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->links[word[i] - 'a']) {
                return false;
            }
            node = node->links[word[i] - 'a'];
        }
        return node->isEnd;
    }
};


bool wordBreak(string s, vector<string>& wordDict) {
    Trie trie;
    for(auto word : wordDict) {
        trie.insert(word);
    }

    int n = s.length();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && trie.search(s.substr(j, i-j))) {
                dp[i] = true;
                break;
            }

        }

    }
    return dp[n];
}

int main() {
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    string s = "catsandog";
    cout << wordBreak(s, wordDict) << endl;

    return 0;
}