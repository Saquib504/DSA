#include <iostream>
using namespace std;

// struct Node
// {
//     Node*list[26];
//     bool flag = false;
//     int cntPrefix = 0;

//     bool containsKey(char ch) {
//         return list[ch - 'a'] != NULL;
//     }

//     void put(char ch, Node* node) {
//         list[ch - 'a'] = node;
//     }

//     Node* get(char ch) {
//         return list[ch - 'a'];
//     }  

//     void increasePrefix() {
//         cntPrefix++;
//     }

//     void setEnd() {
//         flag = true;
//     }

//     bool isEnd() {
//         return flag;
//     }
// };


// class Trie {
// private:
//     Node* root;
// public:
//     Trie() {
//         root = new Node();
//     }

//     void insert(string word) {
//         Node*node = root;
//         for(int i = 0; i < word.length(); i++) {
//             if(!node->containsKey(word[i])){
//                 node->put(word[i], new Node());
//             }
//             node = node->get(word[i]);
//             node->increasePrefix();
//         }
//         node->setEnd();
//     }


//     string longestCommonPrefix(string word, int n) {
//         Node*node = root;
//         string ans = "";
//         for(auto c : word) {
//             if(node->containsKey(c)) {
//                 node = node->get(c);
//                 if(node->cntPrefix == n) {
//                     ans = ans + c;
//                 }
//                 else break;
//             } else break;
//         }
//         return ans;
//     }
// };


// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     // Write your code here
//     auto it = max_element(arr.begin(), arr.end(),
//                           [](const string &a, const string &b) {
//                               return a.size() < b.size();
//                           });

//     Trie trie;
//     for(int i = 0; i < arr.size(); i++) {
//         trie.insert(arr[i]);
//     }

//     return trie.longestCommonPrefix(*it, n);
// }


string longestCommonPrefix(vector<string>& strs) {
if (strs.empty()) return "";

for (int i = 0; i < strs[0].size(); ++i) {
    char c = strs[0][i];
    for (int j = 1; j < strs.size(); ++j) {
        if (i == strs[j].size() || strs[j][i] != c) {
            return strs[0].substr(0, i);
        }
    }
}
return strs[0];
}




int main() {

    vector<string> arr = {"coder", "codingninja", "coding","code","codable"};
    cout << longestCommonPrefix(arr) << endl;

    return 0;
}