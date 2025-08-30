#include <iostream>
#include <unordered_set>
using namespace std;

// struct Node {
//     Node* links[26];
//     bool isWord = false;
// };

// class Trie {
//     Node* root;
// public:
//     Trie() {
//         root = new Node();
//     }

//     void insert(string word) {
//         Node* node = root;
//         for(int i = 0; i < word.length(); i++) {
//             if(!node->links[word[i] - 'a']) {
//                 node->links[word[i] - 'a'] = new Node();
//             }
//             node = node->links[word[i] - 'a'];
//         }
//         node->isWord = true;
//     }

//     // Instead of search, we want to check *prefix while traversing*
//     Node* getRoot() { return root; }
// };


// unordered_map<int, vector<string>> dp; // memoization for sentence

// vector<string> dfs(string &s, int start, Trie &trie) {
//     if (dp.count(start)) return dp[start];
//     vector<string> res;

//     Node* node = trie.getRoot();
//     for (int i = start; i < s.size(); i++) {
//         if (!node->links[s[i] - 'a']) break; // no word with this prefix
//         node = node->links[s[i] - 'a'];
//         if (node->isWord) {
//             string word = s.substr(start, i - start + 1);
//             if (i == s.size() - 1) {
//                 res.push_back(word); // reached end, single word
//             } else {
//                 vector<string> subRes = dfs(s, i + 1, trie);
//                 for (auto &sub : subRes) {
//                     res.push_back(word + " " + sub);
//                 }
//             }
//         }
//     }
//     return dp[start] = res;
// }

// vector<string> wordBreak(string s, vector<string>& wordDict) {
//     // Build trie
//     Trie trie;
//     for (auto &w : wordDict) trie.insert(w);

//     return dfs(s, 0, trie);
// }

unordered_set<string> mpp;
vector<string> res;
void solve(string &s ,int idx,string &curr)
{
    if(idx>=s.length())
    {
        res.push_back(curr);
        return;
    }
    for(int j=idx; j<s.length(); j++)
    {
        string temp=s.substr(idx,j-idx+1);
        if(mpp.count(temp))
        {
            string tempsent=curr;
            if(!curr.empty()){curr+=' ';}
            curr+=temp;
            solve(s,j+1,curr);
            curr=tempsent;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{        // code here
        for(auto temp : dictionary) { mpp.insert(temp);}
        string curr="";
        solve(s,0,curr);
        return res;
}

int main() {
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple","pen","applepen","pine","pineapple"};

    vector<string>ans = wordBreak(s, wordDict);
    for(auto it : ans) {
        cout << it << endl;
    }
}