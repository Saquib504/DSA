#include <iostream>
#include <set>
#include <string>
using namespace std;

// Brute Force Approach
// int isSubstring(string s) {
//     int n = s.length();
//     set<string> st;
//     for(int i = 0; i < n; i++) {
//         string temp = "";
//         for(int j = i; j < n; j++) {
//             temp += s[j];
//             st.insert(temp);
//         }
//     }
//     return st.size();
// }



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
};


int isSubstring(string s) {
    int n = s.length();
    int cnt = 0;
    Node*root = new Node();

    for(int i = 0; i < n; i++) {
        Node*node = root;
        for(int j = i; j < n; j++) {
            if(!node->containsKey(s[j])) {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    
    return cnt;
}




int main() {
    string s = "abab";
    cout << isSubstring(s) << endl;

    return 0;
}