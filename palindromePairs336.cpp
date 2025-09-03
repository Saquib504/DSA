#include <iostream>
using namespace std;



//Optimised Approach
// T.C = O(N*k^2)
// S.C = O(k*N^2)
bool isPalindrome( string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string,int> mpp;
    int idx = 0;
    for(auto x : words){
        string s = x;
        reverse(s.begin(),s.end());
        mpp[s] = idx++;
    }

    vector<vector<int>> ans;

    for(int i = 0; i < words.size(); i++){
        string s = words[i];

        if(s ==""){
            for(auto it : mpp){
                if(it.first != s && isPalindrome(it.first)){
                    ans.push_back({i, it.second});
                    ans.push_back({it.second, i});
                }
            }
            continue;
        }
        if(mpp.find(s) != mpp.end() && mpp[s] != i){ // palindrome of a word is there
            ans.push_back({i, mpp[s]});
        }
        for(int j = 1; j < s.size(); j++){
            string left = s.substr(0, j);
            string right = s.substr(j);
            if(mpp.find(left) != mpp.end() && isPalindrome(right)){
                ans.push_back({i, mpp[left]});
            }
            if(mpp.find(right) != mpp.end() && isPalindrome(left)){
                ans.push_back({mpp[right], i});
            }
        }
    }
    return ans;
    
}



int main() {
    vector<string> words = {"abcd","dcba","lls","s","sssll"};

    vector<vector<int>>ans = palindromePairs(words);

    for(auto it : ans) {
        int u = it[0];
        int v = it[1];

        cout << words[u] + words[v] << endl;
    }

    return 0;
}