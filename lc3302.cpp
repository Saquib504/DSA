#include <iostream>
using namespace std;


vector<int> validSequence(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<int> rightMatched(n, 0);
    int rightMatchCount = 0;
    int i = n-1;
    int j = m-1;

    while(i >= 0) {
        if(j >= 0 && word1[i] == word2[j]) {
            rightMatchCount++;
            j--;
        }

        rightMatched[i] = rightMatchCount;
        i--;
    }

    vector<int> seq;
    i = 0;
    j = 0;

    bool canChange = true;

    while(i < n && j < m) {
        if(word1[i] == word2[j]) {
            seq.push_back(i);
            j++;
        } else if(canChange && i+1 < n && rightMatched[i+1] >= m-j-1) {
            seq.push_back(i);
            canChange = false;
            j++;
        }

        i++;
    }

    if(j == m) return seq;
    return {};
}