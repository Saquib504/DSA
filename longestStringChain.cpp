#include <iostream>
using namespace std;


bool compare(string &a, string &b) {
    if(a.size() != 1+b.size()) return false;

    int i = 0, j = 0;

    while(i < a.size()) {

        if(a[i] == b[j] && j < b.size()) {
            i++;j++;
        }
        else i++;
    }

    if(i == a.size() && j == b.size()) return true;
    return false;
}

int longestStringChain(vector<string>&words) {
    int n = words.size();
    sort(words.begin(), words.end(), [](const string &a, string &b) {
        return a.size() < b.size();
    });

    vector<int>count(n, 1);
    int maxCount = 0;

    for(int i =0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {

            if(compare(words[i], words[prev]) && 1 + count[prev] > count[i]) {
                count[i] = 1 + count[prev];
            }
        }
        maxCount = max(maxCount, count[i]);
    }

    return maxCount;
}

int main() {
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    cout << "The size of Longest String Chain : " << longestStringChain(words) << endl;
    return 0;
}