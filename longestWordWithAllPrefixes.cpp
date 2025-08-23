#include <iostream>
using namespace std;

struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie
{
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfAllPrefixesExist(string word) {
        Node*node = root;
        for(int i = 0; i < word.length(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                if(!node->isEnd()) {
                    return false;
                }
            }else {
                return false;
            }
        }
        return true;
    }
};


string longestString(vector<string> &words) {
    // code here
    string longest = "";
    Trie trie;
    for(auto it : words) {
        trie.insert(it);
    }

    for(auto it : words) {
        if(trie.checkIfAllPrefixesExist(it)) {
            if(it.length() > longest.length()) {
                longest = it;
            }
            else if(it.length() == longest.length() && it < longest) {
                longest = it;
            }
        }
    }
    return longest != "" ? longest : "None";
        
}

int main() {
    vector<string>words = {"n", "ni", "nin", "ninj", "ninja","ninga"};
    cout << "The longest string is: " << longestString(words) << endl;

    return 0;
}